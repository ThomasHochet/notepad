#ifndef NOTEPAD_NOTEPAD_H
#define NOTEPAD_NOTEPAD_H

#include "Menu/Menu.h"
#include "Textarea/Textarea.h"
#include "MarkdownPopup/MarkdownPopup.h"

class Notepad {
private:
    Menu menu;
    Textarea textarea;
    MarkdownPopup markdownPopup;
public:
    Notepad();
    void Render();
    void HandleSave();
    void HandleOpen();
    void HandlePopup();
};


#endif //NOTEPAD_NOTEPAD_H
