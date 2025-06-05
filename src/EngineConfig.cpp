#include "EngineConfig.h"


Config ConfigRead::LoadConfig() {
    YAML::Node data = YAML::LoadFile("assets/config/config.yaml");
    Config config;
    config.images = data["images"].as<std::vector<std::string>>();
    config.width = data["width"].as<unsigned int>();
    config.height = data["height"].as<unsigned int>();
    config.speed = data["speed"].as<float>();
    config.size = data["size"].as<float>();
    config.text = data["text"].as<std::string>();
    config.font = data["font"].as<std::string>();
    config.assets_folder = data["assets_folder"].as<std::string>();
    if (data["color"] && data["color"].IsSequence() && data["color"].size() == 3) {
        for (size_t i = 0; i < 3; ++i) {
            config.color[i] = data["color"][i].as<float>();
        }
    }
    return config;
};