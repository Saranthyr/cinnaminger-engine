#include "Gui.h"

// Специальный колбэк для std::string
static int InputTextCallback(ImGuiInputTextCallbackData* data) {
    if (data->EventFlag == ImGuiInputTextFlags_CallbackResize) {
        // строка передаётся через data->UserData
        std::string* str = static_cast<std::string*>(data->UserData);
        str->resize(data->BufTextLen);
        data->Buf = str->data(); // переназначить буфер
    }
    return 0;
}

void MenuWindow::SetMenuParams(const Menu& newMenu) {
    menu = newMenu;
}

void MenuWindow::Render(Config& config) {
    ImGui::Begin("Hello");
    ImGui::Text("Current image: %d", config.selected_item);

    for (int i = 0; i < config.images.size(); ++i) {
        // The second parameter is a boolean that indicates whether the item is selected
        bool is_selected = (config.selected_item == i);
        if (ImGui::Selectable(config.images[i].c_str(), is_selected)) {
            config.selected_item = i; // Update the selected item
        }
    }

    ImGui::Text("Current text: %s", config.text.c_str());
    ImGui::Text("New text:");
    ImGui::InputText("txt",
        config.text.data(),
        config.text.capacity() + 1,
        ImGuiInputTextFlags_CallbackResize,
        InputTextCallback,
        &config.text);

    ImGui::SliderFloat("Speed", &config.speed, 0.0f, 100.0f);
    ImGui::SliderFloat("Size", &config.size, 0.0f, 1.5f);
    float tempColor[3] = {
        config.color[0] / 255.0f,
        config.color[1] / 255.0f,
        config.color[2] / 255.0f
    };

    if (ImGui::ColorEdit3("Color", tempColor)) {
        config.color[0] = tempColor[0] * 255.0f;
        config.color[1] = tempColor[1] * 255.0f;
        config.color[2] = tempColor[2] * 255.0f;
    }
    ImGui::Text("Current color: (%.2f, %.2f, %.2f)", config.color[0], config.color[1], config.color[2]);
    if (ImGui::Button("Reset pos")) {
        config.resetPos = true;
    }
    ImGui::End();
}