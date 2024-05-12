#include "player.hpp"
#include "menus/menu.hpp"
#include "menus/main.hpp"
#include "draw.hpp"
#include "util.hpp"

// this is mainly just a delegator function to show the appropriate menu
// based on the location
void roc::menu::main(roc::entity::Player& player)
{
    const std::string& location = player.get_location();

    // this could be done with a map but it's more annoying
    // to set up, so this is fine.
    if (location == "Gaya Village")
        roc::menu::location::gaya_village(player); 
    
}

void roc::menu::location::gaya_village(roc::entity::Player& player)
{
    roc::draw::splash_text();

    const std::string& location = player.get_location();
    roc::draw::dialog({"Location: " + location});

    std::cout << "\n";

    uint16_t choice = roc::menu::choice_menu({
        "Character Sheet",
        "Character Journal",
        "Save Game",
        "Alex's Weaponry",
        "Ooglog's Armory",
        "Ferrick's Magic",
        "Gaya Inn",
        "Travel to Outskirt Forest",
        "Travel to Dilapidated Plains"
    });
}
