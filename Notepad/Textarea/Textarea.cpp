#include "Textarea.h"

Textarea::Textarea()  : text("") {}

void Textarea::Render()
{
    ImGuiIO& io = ImGui::GetIO();

    ImVec2 windowPadding = ImGui::GetStyle().WindowPadding;
    ImVec2 availableSize = ImVec2(
            io.DisplaySize.x - 2 * windowPadding.x,
            io.DisplaySize.y - ImGui::GetFrameHeight() - 2 * windowPadding.y
    );

    if (text.capacity() < 2048)
    {
        text.reserve(2048);
    }
    ImGui::InputTextMultiline("##", &text[0], text.capacity() + 1, availableSize);

    text.resize(strlen(text.c_str()));
}


std::string Textarea::GetText() const
{
    return text;
}

void Textarea::SetText(const std::string& newText)
{
    text = newText;
}