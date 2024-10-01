#include "MarkdownPopup.h"
#include "imgui.h"
#include "imgui_md.h"
#include <iostream>
#include "Markdown/Markdown.h"

MarkdownPopup::MarkdownPopup(): text("") {}


void MarkdownPopup::Render(bool* p_open)
{
    char* name = "Markdown render";
    ImGuiIO& io = ImGui::GetIO();
    ImVec2 PopupSize = ImVec2(
            io.DisplaySize.x / 2,
            io.DisplaySize.y / 2
            );


    ImGui::SetNextWindowSize(PopupSize, ImGuiCond_FirstUseEver);

    if (ImGui::Begin(name,
                     p_open,
                     ImGuiWindowFlags_NoCollapse |
                     ImGuiWindowFlags_NoSavedSettings |
                     ImGuiWindowFlags_NoFocusOnAppearing |
                     ImGuiWindowFlags_NoBringToFrontOnFocus))
    {
        markdown(text.c_str(), text.c_str() + text.length());
    }
    ImGui::End();
}

void MarkdownPopup::SetText(std::string newText)
{
    text = std::move(newText);
}

std::string MarkdownPopup::GetText()
{
    return text;
}



