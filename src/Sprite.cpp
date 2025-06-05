#include "Sprite.h"


Sprite::Sprite() : sprite(texture){

}

void Sprite::Update(sf::RenderTarget& target) {
    if (shouldDraw == true) {
        CheckCollision(target);
        sprite.setScale({_xScale, _yScale});
        sprite.setPosition({sprite.getPosition().x + _xSpeed, sprite.getPosition().y + _ySpeed});
    }
}

void Sprite::LoadTexture(std::string Path) {
    if (!texture.loadFromFile(Path)) {
        std::cerr << "Failed to load texture from: " << Path << std::endl;// Exit if texture fails to load
    }
    sprite.setTexture(texture, true);
}

void Sprite::setPos(float xPos, float yPos) {
    sprite.setPosition({xPos, yPos});
}

void Sprite::CheckCollision(sf::RenderTarget& target) {
     sf::FloatRect bounds = sprite.getGlobalBounds();
    sf::Vector2f pos = sprite.getPosition();
    sf::Vector2u windowSize = target.getSize();
    
    // Левая граница
    if (bounds.position.x < 0 && _xSpeed < 0.f) {
        _xSpeed *= -1.0f;
        sprite.setPosition({0.f, pos.y});  // возвращаем в экран
    }

    // Верхняя граница
    if (bounds.position.y < 0 && _ySpeed < 0.f) {
        _ySpeed *= -1.0f;
        sprite.setPosition({pos.x, 0.f});
    }

    // Правая граница
    if (bounds.position.x + bounds.size.x > windowSize.x && _xSpeed > 0.f) {
        _xSpeed *= -1.0f;
        sprite.setPosition({windowSize.x - bounds.size.x, pos.y});
    }

    // Нижняя граница
    if (bounds.position.y + bounds.size.y > windowSize.y && _ySpeed > 0.f) {
        _ySpeed *= -1.0f;
        sprite.setPosition({pos.x, windowSize.y - bounds.size.y});
    }
}

void Sprite::setScale(float xScale, float yScale) {
    _xScale = xScale;
    _yScale = yScale;
    sprite.setOrigin({sprite.getGlobalBounds().size.x/2, sprite.getGlobalBounds().size.y/2});
}

void Sprite::setSpeed(float xSpeed, float ySpeed) {
    if (_xSpeed > 0) {
        _xSpeed = xSpeed;
    }
    else {
        _xSpeed = -1 * xSpeed;
    }
    
    if (_ySpeed > 0) {
        _ySpeed = ySpeed;
    }
    else {
        _ySpeed = -1 * ySpeed;
    }
}

void Sprite::setColor(float r, float g, float b) {
    sprite.setColor(sf::Color(r, g, b));
}

void Sprite::Draw(sf::RenderTarget& target) {
    if (shouldDraw == true) {
        target.draw(sprite);
    }
}
