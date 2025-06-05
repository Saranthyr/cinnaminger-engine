#ifndef ENGINE_TEXT
#define ENGINE_TEXT

#include <iostream>
#include <SFML/Graphics.hpp>
#include "RenderObject.h"

class Text : public RenderObject {
    sf::Font font;
    sf::Text text = sf::Text(font);
    public:
        Text();
        void Draw(sf::RenderTarget& target) override;
        void Update(sf::RenderTarget& target) override;
        void setText(const std::string& newText);
        void LoadFont(std::string Path);
        void setPos(float xPos, float yPos);
        void setColor(float r, float g, float b);
        bool shouldDraw = true;

};


#endif