#include "Menu.h"
#include "imgui.h"
#include <fstream>
#include <iostream>

Menu::Menu() : currentFilePath(""), showOpenDialog(false), showSaveAsDialog(false) {}

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
            if (ImGui::MenuItem("Open"))
            {
                showOpenDialog = true;
            }
            if (ImGui::MenuItem("Save"))
            {
                if (!currentFilePath.empty())
                {
                    SaveFile(fileContent);
                } else
                {
                    showSaveAsDialog = true;
                }
            }
            if (ImGui::MenuItem("Save As..."))
            {
                showSaveAsDialog = true;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    if (showSaveAsDialog)
    {
        ImGui::Begin("Save As", &showSaveAsDialog, ImGuiWindowFlags_AlwaysAutoResize);
        ImGui::Text("Enter file path to save:");
        ImGui::InputText("##saveFilePath", &currentFilePath[0], currentFilePath.capacity() + 1);
        if (ImGui::Button("Save"))
        {
            SaveFile(fileContent);
            showSaveAsDialog = false;
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel"))
        {
            showSaveAsDialog = false;
        }
        ImGui::End();
    }
}

void Menu::OpenFile()
{

}

void Menu::SaveFile(const std::string& textContent)
{
    std::ofstream file(currentFilePath);
    if (file)
    {
        file << textContent;
        file.close();
        std:: cout << "Saved to file: " << currentFilePath << std::endl;
    } else
    {
        std::cerr << "Failed to save file: " << currentFilePath << std::endl;
    }
}