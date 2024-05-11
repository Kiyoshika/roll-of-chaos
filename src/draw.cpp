#include "draw.hpp"
#include "menus/menu.hpp"

void roc::draw::splash_text()
{
    roc::menu::clear_screen();

    std::cout << "    ▄████████  ▄██████▄   ▄█        ▄█             ▄██████▄     ▄████████       ▄████████    ▄█    █▄       ▄████████  ▄██████▄     ▄████████\n";
    std::cout << "    ███    ███ ███    ███ ███       ███            ███    ███   ███    ███      ███    ███   ███    ███     ███    ███ ███    ███   ███    ███\n"; 
    std::cout << "    ███    ███ ███    ███ ███       ███            ███    ███   ███    █▀       ███    █▀    ███    ███     ███    ███ ███    ███   ███    █▀\n";
    std::cout << "   ▄███▄▄▄▄██▀ ███    ███ ███       ███            ███    ███  ▄███▄▄▄          ███         ▄███▄▄▄▄███▄▄   ███    ███ ███    ███   ███\n";
    std::cout << "  ▀▀███▀▀▀▀▀   ███    ███ ███       ███            ███    ███ ▀▀███▀▀▀          ███        ▀▀███▀▀▀▀███▀  ▀███████████ ███    ███ ▀███████████\n";
    std::cout << "  ▀███████████ ███    ███ ███       ███            ███    ███   ███             ███    █▄    ███    ███     ███    ███ ███    ███          ███\n";
    std::cout << "    ███    ███ ███    ███ ███▌    ▄ ███▌    ▄      ███    ███   ███             ███    ███   ███    ███     ███    ███ ███    ███    ▄█    ███\n";
    std::cout << "    ███    ███  ▀██████▀  █████▄▄██ █████▄▄██       ▀██████▀    ███             ████████▀    ███    █▀      ███    █▀   ▀██████▀   ▄████████▀\n";
    std::cout << "    ███    ███            ▀         ▀\n";

    std::cout << " version 0.1 - 11 May 2024\n\n";
}

void roc::draw::solid_line(size_t width)
{
    std::cout << " ";
    for (size_t i = 0; i < width; ++i)
        std::cout << "#";
    std::cout << "\n";
}

void roc::draw::option(const std::string& text, size_t idx, size_t n_options, size_t menu_width)
{
    size_t remaining_space = 0;
    // boundary (#) + space + [ + n_options + ] + space + text
    // = 5 + n_options + text
    size_t option_width = 5 + text.length() + n_options;
    if (option_width < menu_width)
        remaining_space = menu_width - option_width;
    std::cout << " # [" << (idx + 1) << "] " << text;
    for (size_t i = 0; i < remaining_space; ++i)
        std::cout << " ";
    std::cout << "#\n";
}
