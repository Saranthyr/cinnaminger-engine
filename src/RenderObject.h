#ifndef ENGINE_RENDER_OBJ
#define ENGINE_RENDER_OBJ
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class RenderObject {
    public:
        virtual void Draw(sf::RenderTarget&) = 0;
        virtual void Update(sf::RenderTarget&) = 0;
        virtual ~RenderObject() = default;
};


#endif