include(FetchContent)

set(SFML_V 3.0.0)
set(IMGUI_V 1.91.8)
set(IMGUI_SFML_V 3.0)
set(YAML_V 0.8.0)

FetchContent_Declare(
    sfml
    URL "https://github.com/SFML/SFML/archive/${SFML_V}.zip"
)

FetchContent_Declare(
  imgui
  URL "https://github.com/ocornut/imgui/archive/v${IMGUI_V}.zip"
)

FetchContent_Declare(
  imgui-sfml
  URL "https://github.com/SFML/imgui-sfml/archive/v${IMGUI_SFML_V}.zip"
)

FetchContent_Declare(
  yaml
  URL "https://github.com/jbeder/yaml-cpp/archive/refs/tags/${YAML_V}.zip"
)

#sfml
option(SFML_BUILD_AUDIO "Build audio" OFF)
option(SFML_BUILD_NETWORK "Build audio" OFF)
FetchContent_MakeAvailable(sfml)

#imgui
FetchContent_MakeAvailable(imgui)

#imgui-sfml
set(IMGUI_DIR ${imgui_SOURCE_DIR})
option(IMGUI_SFML_FIND_SFML "Use find_package to find SFML" OFF)
option(IMGUI_SFML_IMGUI_DEMO "Build imgui_demo.cpp" OFF)
FetchContent_MakeAvailable(imgui-sfml)

#yaml
FetchContent_MakeAvailable(yaml)


