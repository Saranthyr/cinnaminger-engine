#include "Window.h"

Window::Window() {
    config = ConfigRead::LoadConfig();
    window.create(sf::VideoMode({config.width, config.height}), "Main", (sf::Style::Titlebar, sf::Style::Close));
    window.setPosition({0,0});
    window.setFramerateLimit(165);

    ImGui::SFML::Init(window);
    ImGui::GetStyle().ScaleAllSizes(1.0f);

    Initialize();
}

void Window::Initialize() {
    auto image = std::make_shared<Sprite>();
    auto text = std::make_shared<Text>();

    std::filesystem::path imgPath = std::filesystem::current_path() / config.assets_folder / config.images[0];
    std::filesystem::path fontPath = std::filesystem::current_path() / config.assets_folder / config.font;
    
    image->LoadTexture(imgPath.string());
    image->setScale(config.size, config.size);
    image->setPos(
        static_cast<float>(config.width/2),
        static_cast<float>(config.height/2)
    );
    image->setSpeed(config.speed, config.speed);
    image->setColor(config.color[0], config.color[1], config.color[2]);
    objects.push_back(image);
    
    text->LoadFont(fontPath.string());
    text->setText(config.text);
    text->setPos(static_cast<float>(config.width/2),
        static_cast<float>(config.height/2));
    objects.push_back(text);
}

void Window::DrawObjects() {
    for (const auto& object : objects) {
            if (running == false) {
                if (auto sprite = std::dynamic_pointer_cast<Sprite>(object)) {
                    sprite->shouldDraw = false;
                }
                if (auto sprite = std::dynamic_pointer_cast<Text>(object)) {
                    sprite->shouldDraw = true;
                }                            
            }
            else {
                if (auto sprite = std::dynamic_pointer_cast<Sprite>(object)) {
                    sprite->shouldDraw = true;
                }
                if (auto sprite = std::dynamic_pointer_cast<Text>(object)) {
                    sprite->shouldDraw = false;
                }                            
            
            }
            object->Update(window);
            object->Draw(window);
        }
}

void Window::DrawUI(){
    ui.Render(config);
    auto image = std::dynamic_pointer_cast<Sprite>(objects[0]);
    auto text = std::dynamic_pointer_cast<Text>(objects[1]);
    text->setText(config.text);
    image->LoadTexture((std::filesystem::current_path() / config.assets_folder / config.images[config.selected_item]).string());
    image->setScale(config.size, config.size);
    image->setSpeed(config.speed, config.speed);
    image->setColor(config.color[0], config.color[1], config.color[2]);
    if (config.resetPos == true) {
        image->setPos(
            static_cast<float>(config.width/2),
            static_cast<float>(config.height/2)
        );
        config.resetPos = false;
    }
}

void Window::UpdateUserInput() {
    while (const std::optional event = window.pollEvent()){
        ImGui::SFML::ProcessEvent(window, *event);
        if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }

        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scan::Space && running == true) {
                running = false;
            }
            else if (keyPressed->scancode == sf::Keyboard::Scan::Space && running == false) {
                running = true;
            }
        }
    }
}

void Window::Render() {
    window.clear(sf::Color::Black);
    DrawObjects();
    ImGui::SFML::Render(window);
    window.display();
}

void Window::Run() {

    while (window.isOpen())
    {
        window.clear(sf::Color::Black);
        sf::Time delta = clock.restart();
        ImGui::SFML::Update(window, delta);
        UpdateUserInput();
        DrawObjects();
        DrawUI();
        Render();

    }
    ImGui::SFML::Shutdown();
}