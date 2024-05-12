#include <iostream>
#include "menus/menu.hpp"
#include "menus/character.hpp"
#include "menus/main.hpp"
#include "draw.hpp"
#include "player.hpp"

int main()
{
    roc::draw::splash_text();

    uint16_t choice = 0;
    choice = roc::menu::choice_menu({"New Character", "Load Character"});

    roc::entity::Player player;

    switch (choice)
    {
        case 1:
            roc::menu::character::create(player);
            break;
        case 2:
            roc::menu::character::load(player);
            break;
    }

    roc::menu::main(player);

    return 0;
}
