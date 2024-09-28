#ifndef NOTEPAD_MENU_H
#define NOTEPAD_MENU_H

#include "imgui.h"
#include <iostream>

class Menu
{
private:
    std::string currentFilePath;
    std::string fileContent;
    bool showOpenDialog;
    bool showSaveAsDialog;
public:
    Menu();
    void Render();
    void SaveFile(const std::string& textContent);
    void OpenFile();
};

#endif //NOTEPAD_MENU_H
