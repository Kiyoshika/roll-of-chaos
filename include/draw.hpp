#pragma once

#include <string>
#include <iostream>

namespace roc
{
namespace draw
{
    // main splash text containing the game's title and current version
    void splash_text();

    // solid line: ##############
    void solid_line(size_t width);

    // draw dialog text
    void dialog(const std::vector<std::string>& text);

    // option line: # [X] option text here   #
    void option(const std::string& text, size_t idx, size_t n_options, size_t menu_width);
}; // namespace draw
}; // namespace roc
