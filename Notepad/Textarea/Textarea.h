#ifndef NOTEPAD_TEXTAREA_H
#define NOTEPAD_TEXTAREA_H

#include <iostream>
#include "imgui.h"

class Textarea {
private:
    std::string text;
    static int ResizeCallback(ImGuiInputTextCallbackData* data);
    static int TextareaCallback(ImGuiInputTextCallbackData *data);

    int cursorPos;
public:
    Textarea();
    void Render();
    [[nodiscard]] std::string GetText() const;
    void SetText(const std::string& newText);
    void InsertTextCursorPosition(const std::string& characters);
};


#endif //NOTEPAD_TEXTAREA_H
