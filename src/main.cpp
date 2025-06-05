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
#include <memory>
#include <stdexcept>
#include <stdio.h>
#include <yaml-cpp/yaml.h>
#include "EngineConfig.h"
#include "Window.h"
#include "Sprite.h"
#include "RenderObject.h"

int main (int argc, char *argv[]) {
    Window window;
    window.Run();
    
    return 0;
}
