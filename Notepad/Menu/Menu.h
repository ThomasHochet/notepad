#ifndef NOTEPAD_MENU_H
#define NOTEPAD_MENU_H

#include "imgui.h"
#include <iostream>

class Menu
{
private:
    std::string currentFilePath;
    std::string fileContent;
    bool* isMarkdownViewVisible;
    bool* boldSelected;
    bool* underlineSelected;
    bool* strikethroughSelected;
    // bool italicSelected - no italic in markdown render.
public:
    Menu();
    void Render();
    void SaveFile(const std::string& textContent);
    void OpenFile();
    std::string GetFileContent();
    void SetIsMarkdownViewVisible(bool* isNewMarkdownViewVisible);
    bool* GetIsMarkdownViewVisible();
    void SetBoldSelected(bool* bold);
    void SetUnderlinedSelected(bool* underline);
    void SetStrikethroughSelected(bool* strikethrough);
};

#endif //NOTEPAD_MENU_H
