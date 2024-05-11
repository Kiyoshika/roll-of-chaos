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

void roc::draw::dialog(const std::vector<std::string>& text)
{
    size_t max_text_len = 0;
    for (const std::string& line : text)
        if (line.length() > max_text_len)
            max_text_len = line.length();

    size_t width = max_text_len + 4;
    std::cout << " ";
    roc::draw::solid_line(width);

    for (const std::string& line : text)
    {
        std::cout << " # " << line;

        size_t remaining_len = 0;
        if (line.length() + 2 < width)
            remaining_len = width - line.length() - 2;
        for (size_t i = 0; i < remaining_len; ++i)
            std::cout << " ";
        std::cout << "#\n";
    }
    
    roc::draw::solid_line(width);
}

void roc::draw::option(const std::string& text, size_t idx, size_t n_options, size_t menu_width)
{
    size_t remaining_space = 0;
    // format: # [XYZ] options text ... #
    size_t option_width = 5 + text.length() + (n_options/10) + 2;
    if (option_width < menu_width)
        remaining_space = menu_width - option_width;
    std::cout << " # [" << (idx + 1) << "] " << text;
    for (size_t i = 0; i < remaining_space; ++i)
        std::cout << " ";
    std::cout << "#\n";
}
