#include "menus/menu.hpp"
#include "draw.hpp"

std::string roc::menu::get_text_input(const std::string& prompt)
{
    std::string response = "";
    while (true)
    {
        std::cout << "\n " << prompt << "\n >> ";
        std::cin >> response;
        if (response.length() > 0 && response.find(" ") == std::string::npos)
            break;
    }

    return response;
}

void roc::menu::clear_screen()
{
    for (size_t i = 0; i < 10000; ++i)
        std::cout << "\n";
}

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
            if (choice > 0 && choice <= n_options)
                break;
        }
        catch(const std::exception& ex) {}
    }

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
        roc::draw::option(options[i], i, options.size(), width);
    

    // draw the floor of the menu
    roc::draw::solid_line(width);

    return roc::menu::get_choice(options.size());
}
