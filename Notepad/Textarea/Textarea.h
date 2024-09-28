#ifndef NOTEPAD_TEXTAREA_H
#define NOTEPAD_TEXTAREA_H

#include <iostream>
#include "imgui.h"

class Textarea {
private:
    std::string text;
public:
    Textarea();
    void Render();
    [[nodiscard]] std::string GetText() const;
    void SetText(const std::string& newText);
};


#endif //NOTEPAD_TEXTAREA_H
