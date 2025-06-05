set(TARGET_NAME main)
set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
set(CONFIG_PATH "${ASSETS_DIR}/configs/config.yaml")
# set(SRC main_2.cpp)
set(SRC main.cpp
EngineConfig.h EngineConfig.cpp
Window.h Window.cpp
Sprite.h Sprite.cpp
Gui.h Gui.cpp
Text.h Text.cpp)


add_executable(${TARGET_NAME} ${SRC})

target_compile_features(${TARGET_NAME} PRIVATE cxx_std_20)
# target_include_directories(${TARGET_NAME} PRIVATE ${SRC})
target_compile_definitions(${TARGET_NAME} PRIVATE ASSETS_DIR=${ASSETS_DIR} CONFIG_PATH=${CONFIG_PATH})
target_link_libraries(${TARGET_NAME} PUBLIC ImGui-SFML::ImGui-SFML yaml-cpp::yaml-cpp)

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${ASSETS_DIR}
            "$<TARGET_FILE_DIR:${TARGET_NAME}>/assets"
    COMMENT "Copying assets to the executable directory"
)
