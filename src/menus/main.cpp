#include "player.hpp"
#include "menus/menu.hpp"
#include "menus/main.hpp"
#include "draw.hpp"
#include "util.hpp"

void roc::menu::main(roc::entity::Player& player)
{
    roc::draw::splash_text();

    roc::draw::dialog({"Location: " + player.get_location()});
    
    uint16_t choice = roc::menu::choice_menu({
        "Character Sheet",
        "Shops",
        "Travel"
    });
}
