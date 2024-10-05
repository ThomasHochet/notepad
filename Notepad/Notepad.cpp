#include "Notepad.h"
#include <SDL.h>

extern SDL_Texture* bold_texture;
extern SDL_Texture* underline_texture;
extern SDL_Texture* strikethrough_texture;

Notepad::Notepad() :
menu(),
textarea(),
markdownPopup(),
markdownViewVisible(false),
boldSelected(false),
underlineSelected(false),
strikethroughSelected(false) {
    menu.SetIsMarkdownViewVisible(&markdownViewVisible);
    menu.SetBoldSelected(&boldSelected);
    menu.SetUnderlinedSelected(&underlineSelected);
    menu.SetStrikethroughSelected(&strikethroughSelected);
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

    ImGuiID dockspace_id = ImGui::GetID("NotepadDockspace");
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);

    menu.Render();
    textarea.Render();

    if (ImGui::IsKeyPressed(ImGuiKey_B) && (ImGui::GetIO().KeyCtrl))
    {
        boldSelected = true;
    }
    if (ImGui::IsKeyPressed(ImGuiKey_U) && (ImGui::GetIO().KeyCtrl))
    {
        underlineSelected = true;
    }
    if (ImGui::IsKeyPressed(ImGuiKey_T) && (ImGui::GetIO().KeyCtrl))
    {
        strikethroughSelected = true;
    }

    if (boldSelected)
    {
        textarea.InsertTextCursorPosition("**");
        boldSelected = false;
    }
    if (underlineSelected)
    {
        textarea.InsertTextCursorPosition("__");
        underlineSelected = false;
    }
    if (strikethroughSelected)
    {
        textarea.InsertTextCursorPosition("~~");
        strikethroughSelected = false;
    }

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