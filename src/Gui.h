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

class MenuWindow {
    public:
        void Render(Config& config);
};

#endif