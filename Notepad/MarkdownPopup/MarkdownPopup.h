#ifndef NOTEPAD_MARKDOWNPOPUP_H
#define NOTEPAD_MARKDOWNPOPUP_H

#include "imgui.h"
#include <iostream>

class MarkdownPopup {
private:
    std::string text;
public:
    MarkdownPopup();
    void Render();
    void SetText(std::string newText);
    std::string GetText();
};


#endif //NOTEPAD_MARKDOWNPOPUP_H
