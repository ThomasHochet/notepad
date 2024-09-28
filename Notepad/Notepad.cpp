#include "Notepad.h"

Notepad::Notepad() : menu(), textarea() {}

void Notepad::Render()
{
    ImGuiIO& io = ImGui::GetIO();
    ImGui::Begin("Notepad",
                 nullptr,
                 ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
    ImGui::SetWindowSize(io.DisplaySize);
    ImGui::SetWindowPos(ImVec2(0, 0));

    menu.Render();
    textarea.Render();

    if (ImGui::IsKeyPressed(ImGuiKey_S) && (ImGui::GetIO().KeyCtrl))
    {
        HandleSave();
    }

    ImGui::End();
}

void Notepad::HandleSave()
{
    std::string textContent = textarea.GetText();
    menu.SaveFile(textContent);
}