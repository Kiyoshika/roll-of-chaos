#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace roc
{
namespace menu
{
    // "clear" the screen
    void clear_screen();

    std::string get_text_input(const std::string& prompt);

    // promps the user for a valid numerical input for a menu
    uint16_t get_choice(size_t n_options);

    // display arbitrary choice menu
    uint16_t choice_menu(const std::vector<std::string>& options);

    // main titlescreen of the game when launching
    uint16_t title_screen();
}; // namespace menu
}; // namespace roc
