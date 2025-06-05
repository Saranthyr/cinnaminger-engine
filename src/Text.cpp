#include "Text.h"

Text::Text() {
    
}

void Text::Draw(sf::RenderTarget& target) {
    if (shouldDraw == true) {
        target.draw(text);
    }
}

void Text::setText(const std::string& newText) {
    text.setString(newText);
}

void Text::LoadFont(std::string Path) {
     if (!font.openFromFile(Path)) {
        std::cerr << "Failed to load texture from: " << Path << std::endl;// Exit if texture fails to load
    }
    text.setFont(font);
}

void Text::setPos(float xPos, float yPos) {
    text.setPosition({xPos - text.getCharacterSize(), yPos});
}

void Text::setColor(float r, float g, float b) {
    text.setFillColor(sf::Color(r, g, b));
}

void Text::Update(sf::RenderTarget& target) {

}