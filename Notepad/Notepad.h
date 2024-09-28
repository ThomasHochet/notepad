#ifndef NOTEPAD_NOTEPAD_H
#define NOTEPAD_NOTEPAD_H

#include "Menu/Menu.h"
#include "Textarea/Textarea.h"

class Notepad {
private:
    Menu menu;
    Textarea textarea;
public:
    Notepad();
    void Render();
    void HandleSave();
};


#endif //NOTEPAD_NOTEPAD_H
