set(TARGET_NAME main)
set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
set(CONFIG_PATH "${ASSETS_DIR}/configs/config.yaml")
set(SRC main.cpp)


add_executable(${TARGET_NAME} ${SRC})

target_compile_features(${TARGET_NAME} PRIVATE cxx_std_20)
target_compile_definitions(${TARGET_NAME} PRIVATE ASSETS_DIR=${ASSETS_DIR} CONFIG_PATH=${CONFIG_PATH})
target_link_libraries(${TARGET_NAME} PUBLIC ImGui-SFML::ImGui-SFML yaml-cpp::yaml-cpp)