#include "MarkdownPopup.h"
#include "imgui.h"
#include "imgui_markdown.h"
#include <iostream>

MarkdownPopup::MarkdownPopup(): text("") {}

static ImGui::MarkdownConfig mdConfig;

void MarkdownPopup::Render()
{
    ImGuiIO& io = ImGui::GetIO();
    ImVec2 PopupSize = ImVec2(
            io.DisplaySize.x / 2,
            io.DisplaySize.y / 2
            );
    ImGui::SetNextWindowSize(PopupSize, ImGuiCond_Always);
    if (ImGui::Begin("Markdown render"))
    {
        ImGui::Markdown( text.c_str(), text.length(), mdConfig );
    }
    ImGui::End();
}

void MarkdownPopup::SetText(std::string newText)
{
    text = newText;
}

std::string MarkdownPopup::GetText()
{
    return text;
}



