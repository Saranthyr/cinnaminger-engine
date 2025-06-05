#ifndef ENGINE_GUI
#define ENGINE_GUI

#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "imgui.h"
#include "imgui-SFML.h"
#include "RenderObject.h"
#include "EngineConfig.h"

struct Menu {
    std::vector<std::string> Items = {
        "BluRay",
        "DVD",
        "CD"
    };
    float color[3];
};

class MenuWindow {
    public:
        void SetMenuParams(const Menu& newMenu);
        void Render(Config& config);
    private:
        Menu menu;
};


#endif