#include "Notepad.h"

Notepad::Notepad() : menu(), textarea(), markdownPopup() {}

void Notepad::Render()
{
    ImGuiIO& io = ImGui::GetIO();
    ImGui::Begin("Notepad",
                 nullptr,
                 ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus);
    ImGui::SetWindowSize(io.DisplaySize);
    ImGui::SetWindowPos(ImVec2(0, 0));

    menu.Render();
    textarea.Render();
    if (menu.GetIsMarkdownViewVisible())
    {
        ImGui::OpenPopup("Markdown render");
        markdownPopup.SetText(textarea.GetText());
        markdownPopup.Render();
    }

    if (ImGui::IsKeyPressed(ImGuiKey_S) && (ImGui::GetIO().KeyCtrl))
    {
        HandleSave();
    }

    if (ImGui::IsKeyPressed(ImGuiKey_O) && (ImGui::GetIO().KeyCtrl))
    {
        HandleOpen();
    }

    if (ImGui::IsKeyPressed(ImGuiKey_B) && (ImGui::GetIO().KeyCtrl))
    {
        HandlePopup();
    }

    if (!menu.GetFileContent().empty())
    {
        textarea.SetText(menu.GetFileContent());
    }

    ImGui::End();
}

void Notepad::HandleSave()
{
    std::string textContent = textarea.GetText();
    menu.SaveFile(textContent);
}

void Notepad::HandleOpen()
{
    menu.OpenFile();
    textarea.SetText(menu.GetFileContent());
}

void Notepad::HandlePopup()
{
    bool swapVisiblePopup = !menu.GetIsMarkdownViewVisible();
    menu.SetIsMarkdownViewVisible(swapVisiblePopup);
}