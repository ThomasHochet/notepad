#ifndef NOTEPAD_TEXTAREA_H
#define NOTEPAD_TEXTAREA_H

#include <iostream>
#include "imgui.h"

class Textarea {
private:
    std::string text;
    static int ResizeCallback(ImGuiInputTextCallbackData* data);

    bool boldText;
    bool italicText;
    bool underlineText;
public:
    Textarea();
    void Render();
    [[nodiscard]] std::string GetText() const;
    void SetText(const std::string& newText);
};


#endif //NOTEPAD_TEXTAREA_H
