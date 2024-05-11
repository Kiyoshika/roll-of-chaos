#include "menu.hpp"
#include "draw.hpp"

uint16_t roc::menu::get_choice(size_t n_options)
{
    std::string user_input = "";
    uint16_t choice = 0;
    while (true)
    {
        std::cout << "\n >> ";
        std::cin >> user_input;
        try
        {
            std::stringstream sstream(user_input);
            sstream >> choice;
            if (choice > 0 && choice < n_options)
                break;
        }
        catch(const std::exception& ex) {}
    }

    std::cout << "CHOICE: " << choice;

    return choice;
}

uint16_t roc::menu::choice_menu(const std::vector<std::string>& options)
{
    size_t max_option_len = 0;
    size_t n_options = options.size();
    for (const std::string& opt : options)
        if (opt.length() > max_option_len)
            max_option_len = opt.length();

    // boundary (#) + space + [ + n_options + ] + space + max_option_len + space + boundary (#)
    // = 7 + n_options + max_option_len
    size_t width = 7 + n_options + max_option_len;
    
    // draw top of menu
    roc::draw::solid_line(width);

    // draw individual options
    for (size_t i = 0; i < options.size(); ++i)
        roc::draw::option(options[i], i, options.size(), max_option_len, width);
    

    // draw the floor of the menu
    roc::draw::solid_line(width);

    return roc::menu::get_choice(options.size());
}

uint16_t roc::menu::title_screen(const std::string& version)
{
    
    std::cout << "    ▄████████  ▄██████▄   ▄█        ▄█             ▄██████▄     ▄████████       ▄████████    ▄█    █▄       ▄████████  ▄██████▄     ▄████████\n";
    std::cout << "    ███    ███ ███    ███ ███       ███            ███    ███   ███    ███      ███    ███   ███    ███     ███    ███ ███    ███   ███    ███\n"; 
    std::cout << "    ███    ███ ███    ███ ███       ███            ███    ███   ███    █▀       ███    █▀    ███    ███     ███    ███ ███    ███   ███    █▀\n";
    std::cout << "   ▄███▄▄▄▄██▀ ███    ███ ███       ███            ███    ███  ▄███▄▄▄          ███         ▄███▄▄▄▄███▄▄   ███    ███ ███    ███   ███\n";
    std::cout << "  ▀▀███▀▀▀▀▀   ███    ███ ███       ███            ███    ███ ▀▀███▀▀▀          ███        ▀▀███▀▀▀▀███▀  ▀███████████ ███    ███ ▀███████████\n";
    std::cout << "  ▀███████████ ███    ███ ███       ███            ███    ███   ███             ███    █▄    ███    ███     ███    ███ ███    ███          ███\n";
    std::cout << "    ███    ███ ███    ███ ███▌    ▄ ███▌    ▄      ███    ███   ███             ███    ███   ███    ███     ███    ███ ███    ███    ▄█    ███\n";
    std::cout << "    ███    ███  ▀██████▀  █████▄▄██ █████▄▄██       ▀██████▀    ███             ████████▀    ███    █▀      ███    █▀   ▀██████▀   ▄████████▀\n";
    std::cout << "    ███    ███            ▀         ▀\n";

    std::cout << " version " << version << " - 11 May 2024\n\n";

    return roc::menu::choice_menu({"New Character", "Load Character"});
}
