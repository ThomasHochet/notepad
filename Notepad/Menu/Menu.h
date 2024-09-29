#ifndef NOTEPAD_MENU_H
#define NOTEPAD_MENU_H

#include "imgui.h"
#include <iostream>

class Menu
{
private:
    std::string currentFilePath;
    std::string fileContent;
    bool isMarkdownViewVisible;
public:
    Menu();
    void Render();
    void SaveFile(const std::string& textContent);
    void OpenFile();
    std::string GetFileContent();
    void SetIsMarkdownViewVisible(bool isNewMarkdownViewVisible);
    bool GetIsMarkdownViewVisible();
};

#endif //NOTEPAD_MENU_H
