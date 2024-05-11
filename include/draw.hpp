#pragma once

#include <string>
#include <iostream>

namespace roc
{
namespace draw
{
    void solid_line(size_t width);
    void option(const std::string& text, size_t idx, size_t n_options, size_t max_option_len, size_t menu_width);
}; // namespace draw
}; // namespace roc
