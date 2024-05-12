#include <iostream>
#include "menus/menu.hpp"
#include "menus/character.hpp"
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
            player = roc::menu::character::create();
            break;
        case 2:
            player = roc::menu::character::load();
            break;
    }

    return 0;
}
