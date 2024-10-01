#include "Notepad.h"

Notepad::Notepad() : menu(), textarea(), markdownPopup(), markdownViewVisible(false) {
    menu.SetIsMarkdownViewVisible(&markdownViewVisible);
}

void Notepad::Render()
{
    ImGuiIO& io = ImGui::GetIO();
    ImGuiViewport* viewport = ImGui::GetMainViewport();

    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);
    ImGui::Begin("Notepad",
                 nullptr,
                 ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize  | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);

    menu.Render();
    textarea.Render();

    if (menu.GetIsMarkdownViewVisible() && *menu.GetIsMarkdownViewVisible())
    {
        markdownPopup.SetText(textarea.GetText());
        markdownPopup.Render(menu.GetIsMarkdownViewVisible());
    }

    if (ImGui::IsKeyPressed(ImGuiKey_S) && (ImGui::GetIO().KeyCtrl))
    {
        HandleSave();
    }

    if (ImGui::IsKeyPressed(ImGuiKey_O) && (ImGui::GetIO().KeyCtrl))
    {
        HandleOpen();
    }

    if (ImGui::IsKeyPressed(ImGuiKey_B) && (ImGui::GetIO().KeyCtrl) && (ImGui::GetIO().KeyShift))
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
    markdownViewVisible = !markdownViewVisible;
    menu.SetIsMarkdownViewVisible(&markdownViewVisible);
}