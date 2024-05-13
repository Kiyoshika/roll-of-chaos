#include "player.hpp"
#include "menus/menu.hpp"
#include "menus/main.hpp"
#include "draw.hpp"
#include "util.hpp"

void roc::menu::main(roc::entity::Player& player)
{
    const std::string& location = player.get_location_name();

    roc::draw::splash_text();

    roc::draw::dialog({"Location: " + location});

    std::cout << "\n";

    auto menu_options = player.get_location().get_menu_options();

    std::vector<std::string> option_names;
    for (const auto& option : menu_options)
        option_names.push_back(option.first);

    uint16_t choice = roc::menu::choice_menu(option_names);
    menu_options[choice - 1].second(player);
}
