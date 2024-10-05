#include "Menu.h"
#include "imgui.h"
#include <fstream>
#include <iostream>
#include <nfd.h>
#include <string>

Menu::Menu() : currentFilePath(""), isMarkdownViewVisible(nullptr) {}

void Menu::Render()
{
    if(ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("New"))
            {
                fileContent.clear();
            }
            if (ImGui::MenuItem("Open (Ctrl+O"))
            {
                OpenFile();
            }
            if (ImGui::MenuItem("Save (Ctrl+S)"))
            {
                if (!currentFilePath.empty())
                {
                    SaveFile(fileContent);
                } else
                {
                    SaveFile(fileContent);
                }
            }
            if (ImGui::MenuItem("Save As..."))
            {
                if (!currentFilePath.empty())
                {
                    SaveFile(fileContent);
                } else
                {
                    SaveFile(fileContent);
                }
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("View"))
        {
            if (ImGui::MenuItem("Markdown (Ctrl+Shift+B)", nullptr, isMarkdownViewVisible))
            {
            }
            ImGui::EndMenu();
        }

        ImGui::SameLine();
        ImGui::Spacing();
        ImGui::SameLine();

        if (ImGui::Button("B"))
            *boldSelected = !(*boldSelected);
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("Bold (Ctrl+B)");

        ImGui::SameLine();
        if (ImGui::Button("U"))
            *underlineSelected = !(*underlineSelected);
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("Underline (Ctrl+U)");

        ImGui::SameLine();
        if (ImGui::Button("S"))
            *strikethroughSelected = !(*strikethroughSelected);
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("Strikethrough (Ctrl+T)");

        ImGui::EndMenuBar();
    }
}

void Menu::OpenFile()
{
    nfdchar_t *outPath = nullptr;
    nfdresult_t  result = NFD_OpenDialog(nullptr, nullptr, &outPath);

    if (result == NFD_OKAY)
    {
        currentFilePath = outPath;
        free(outPath);

        std::ifstream file(currentFilePath);
        if (file)
        {
            fileContent = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            file.close();

            std::cout << "Opened file: " << currentFilePath << std::endl;
        } else
        {
            std::cerr << "Failed to open file: " << currentFilePath << std::endl;
        }
    } else if (result == NFD_CANCEL)
    {
        std::cout << "User cancelled file open." << std::endl;
    } else
    {
        std::cerr << "Error: " << NFD_GetError() << std::endl;
    }
}

std::string Menu::GetFileContent()
{
    return fileContent;
}

void Menu::SaveFile(const std::string& textContent)
{
    if (currentFilePath.empty())
    {
        nfdchar_t *outPath = nullptr;
        nfdresult_t result = NFD_SaveDialog(nullptr, nullptr, &outPath);

        if (result == NFD_OKAY)
        {
            currentFilePath = outPath;
            free(outPath);
        } else
        {
            std::cout << "User cancelled file save." << std::endl;
        }
    }

    std::ofstream file(currentFilePath);
    if (file)
    {
        file << textContent;
        file.close();
        std::cout << "Saved to file: " << currentFilePath << std::endl;
    } else
    {
        std::cerr << "Failed to save file: " << currentFilePath << std::endl;
    }
}

void Menu::SetIsMarkdownViewVisible(bool* isNewMarkdownViewVisible)
{
    isMarkdownViewVisible = isNewMarkdownViewVisible;
}

bool* Menu::GetIsMarkdownViewVisible()
{
    return isMarkdownViewVisible;
}

void Menu::SetBoldSelected(bool* bold)
{
   boldSelected = bold;
}

void Menu::SetUnderlinedSelected(bool* underline)
{
    underlineSelected = underline;
}

void Menu::SetStrikethroughSelected(bool* strikethrough)
{
    strikethroughSelected = strikethrough;
}