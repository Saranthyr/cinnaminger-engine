#ifndef ENGINE_WINDOW
#define ENGINE_WINDOW

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>  
#include <iostream>
#include <fstream>
#include <filesystem>
#include <memory>
#include <typeinfo>
#include <string.h>
#include <stdexcept>
#include <stdio.h>
#include "EngineConfig.h"
#include "Sprite.h"
#include "Text.h"
#include "Gui.h"

class Window {
    public:
        Window();
        void Run();
        // void AddToObjects(std::shared_ptr<RenderObject> object);
    private:
        void Initialize();
        void DrawObjects();
        void DrawUI();
        void UpdateUserInput();
        void Render();
        Menu menu;
        MenuWindow ui;
        sf::RenderWindow window;
        sf::Clock clock;
        Config config;
        std::vector<std::shared_ptr<RenderObject>> objects;
        bool running = true;
};  
#endif