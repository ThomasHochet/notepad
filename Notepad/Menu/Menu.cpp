#include "Menu.h"
#include "imgui.h"
#include <fstream>
#include <iostream>
#include <nfd.h>
#include <string>

Menu::Menu() : currentFilePath(""), isMarkdownViewVisible(false) {}

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
            if (ImGui::MenuItem("Markdown (Ctrl+B)", nullptr, &isMarkdownViewVisible))
            {
            }
            ImGui::EndMenu();
        }
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

void Menu::SetIsMarkdownViewVisible(bool isNewMarkdownViewVisible)
{
    isMarkdownViewVisible = isNewMarkdownViewVisible;
}

bool Menu::GetIsMarkdownViewVisible()
{
    return isMarkdownViewVisible;
}