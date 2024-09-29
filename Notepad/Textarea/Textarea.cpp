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

    ImGui::InputTextMultiline(
            "##",
            &text[0],
            text.capacity() + 1,
            availableSize,
            ImGuiInputTextFlags_CallbackResize | ImGuiInputTextFlags_AllowTabInput | ImGuiWindowFlags_NoBringToFrontOnFocus,
            ResizeCallback,
            (void*)&text
            );

    text.resize(strlen(text.c_str()));
}

int Textarea::ResizeCallback(ImGuiInputTextCallbackData *data)
{
    if (data->EventFlag == ImGuiInputTextFlags_CallbackResize)
    {
        std::string* str = (std::string*)data->UserData;
        str->resize(data->BufTextLen);
        data->Buf = (char*)str->c_str();
    }
    return 0;
}

std::string Textarea::GetText() const
{
    return text;
}

void Textarea::SetText(const std::string& newText)
{
    text = newText;
    text.resize((newText.size()));

    if (text.capacity() < newText.size() + 1)
    {
        text.reserve(newText.size() + 1);
    }
}