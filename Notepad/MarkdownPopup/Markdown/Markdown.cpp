#include "Markdown.h"
#include "imgui_md.h"
#include "SDL.h"

extern ImFont* g_font_regular;
extern ImFont* g_font_bold;
extern ImFont* g_font_bold_large;
extern ImTextureID g_texture1;

ImFont *my_markdown::get_font() const
{
    if (m_is_table_header) {
        return g_font_bold;
    }

    switch (m_hlevel)
    {
        case 0:
            return m_is_strong ? g_font_bold : g_font_regular;
        case 1:
            return g_font_bold_large;
        default:
            return g_font_bold;
    }
}

void my_markdown::open_url() const
{
    SDL_OpenURL(m_href.c_str());
}

bool my_markdown::get_image(image_info &nfo) const
{
    //use m_href to identify images
    nfo.texture_id = g_texture1;
    nfo.size = {40,20};
    nfo.uv0 = { 0,0 };
    nfo.uv1 = {1,1};
    nfo.col_tint = { 1,1,1,1 };
    nfo.col_border = { 0,0,0,0 };
    return true;
}

void my_markdown::html_div(const std::string &dclass, bool e)
{
    if (dclass == "red") {
        if (e) {
            m_table_border = false;
            ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
        } else {
            ImGui::PopStyleColor();
            m_table_border = true;
        }
    }
}

void markdown(const char* str, const char* str_end)
{
    static my_markdown s_printer;
    s_printer.print(str, str_end);
}