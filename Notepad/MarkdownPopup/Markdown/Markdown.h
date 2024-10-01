#ifndef NOTEPAD_MARKDOWN_H
#define NOTEPAD_MARKDOWN_H

#include "imgui_md.h"

struct my_markdown : public imgui_md
{
    ImFont* get_font() const override;
    void open_url() const override;
    bool get_image(image_info& nfo) const override;
    void html_div(const std::string& dclass, bool e) override;
};

void markdown(const char* str, const char* str_end);

#endif //NOTEPAD_MARKDOWN_H
