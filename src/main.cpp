#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>  
#include <imgui.h>
#include <imgui-SFML.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <typeinfo>
#include <string.h>
#include <stdexcept>
#include <stdio.h>


int main (int argc, char *argv[]) {
    auto fullPath = std::filesystem::current_path() / "DVDLogo.png";
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Window", (sf::Style::Titlebar, sf::Style::Close));
    ImGui::SFML::Init(window);
    window.setPosition({0,0});
    int WINDOW_W = window.getSize().x;
    int WINDOW_H = window.getSize().y;
    sf::Texture logoTex;
    if (!logoTex.loadFromFile(fullPath)) {
        std::cerr << "Failed to load texture from: " << fullPath << std::endl;
        return 1;  // Exit if texture fails to load
    }
    logoTex.setSmooth(true);
    float speed = 0.5f;
    sf::Sprite spriteLogo(logoTex);
    spriteLogo.setScale({0.25f, 0.25f});
    spriteLogo.setPosition({
        (static_cast<float>(WINDOW_W)/2) - spriteLogo.getGlobalBounds().size.x/2,
        (static_cast<float>(WINDOW_H)/2) - spriteLogo.getGlobalBounds().size.y/2
    });
    sf::Vector2f velocity({speed, speed});
    bool pause = false;
    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Vector2i windowOffset = window.getPosition();
        while (const std::optional event = window.pollEvent())
            {
                ImGui::SFML::ProcessEvent(window, *event);
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
                if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                    if (keyPressed->scancode == sf::Keyboard::Scan::Pause && pause == true) {
                        pause = false;
                    }
                    else if (keyPressed->scancode == sf::Keyboard::Scan::Pause && pause == false) {
                        pause = true;
                    }
                }
                if (event->is<sf::Event::Resized>()) {
                    std::cout << window.getSize().x << " " << window.getSize().y << std::endl;
                }
                if (event->is<sf::Event::TouchMoved>()) {

                }
            }
            if (pause == false) {
                ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::ShowDemoWindow();

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();
                spriteLogo.move(velocity);
                sf::Vector2f boundsPos = spriteLogo.getGlobalBounds().position;
                sf::Vector2f boundsSize = spriteLogo.getGlobalBounds().size;
                if (boundsPos.x < 0 && velocity.x < 0) {
                    velocity.x *= -1.0f;
                }
                if (boundsPos.y < 0 && velocity.y < 0) {
                    velocity.y *= -1.0f;
                }

                if (boundsPos.x + boundsSize.x > window.getSize().x && velocity.x > 0) {
                    velocity.x *= -1.0f;
                }
                if (boundsPos.y + boundsSize.y > window.getSize().y && velocity.y > 0) {
                    velocity.y *= -1.0f;
                    
                }
                window.clear(sf::Color::Black);
                window.draw(spriteLogo);
                sf::RectangleShape boundsRect(spriteLogo.getGlobalBounds().size);
                boundsRect.setPosition({spriteLogo.getGlobalBounds().position.x,
                    spriteLogo.getGlobalBounds().position.y});
                boundsRect.setOutlineColor(sf::Color::Red);
                boundsRect.setOutlineThickness(5.0f);
                boundsRect.setFillColor(sf::Color::Transparent);
                window.draw(boundsRect);
                ImGui::SFML::Render(window);
            }
        window.display();
    }
    
    return 0;
}
