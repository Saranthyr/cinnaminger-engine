#ifndef ENGINE_CONFIG
#define ENGINE_CONFIG
#include <yaml-cpp/yaml.h>
#include <iostream>
#include <string>
#include <vector>

struct Config {
    std::vector<std::string> images;
    int selected_item = 0;
    unsigned int width = 0;
    unsigned int height = 0;
    float speed = 0.0f;
    float size = 0.0f;
    std::string text;
    std::string font;
    std::string assets_folder;
    float color[3];
    bool resetPos = false;
};

class ConfigRead {
    public:
        static Config LoadConfig();
};

#endif