#ifndef ENGINE_SPRITE
#define ENGINE_SPRITE
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "RenderObject.h"

class Sprite : public RenderObject {
    public:
        Sprite();
        void LoadTexture(std::string Path);
        void Draw(sf::RenderTarget& target) override;
        void Update(sf::RenderTarget& target) override;
        void setColor(float r, float g, float b);
        void setScale(float scaleX, float scaleY);
        void setSpeed(float speedX, float speedY);
        void setPos(float xPos, float yPos);
        bool shouldDraw = true;
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        float _xScale = 0.5f;
        float _yScale = 0.5f;
        float _xSpeed = 0.1f;
        float _ySpeed = 0.1f;
        void CheckCollision(sf::RenderTarget& target);
};

#endif