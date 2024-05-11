#include <iostream>
#include "menus/menu.hpp"
#include "menus/character.hpp"
#include "draw.hpp"

int main()
{
    roc::draw::splash_text();

    uint16_t choice = 0;
    choice = roc::menu::choice_menu({"New Character", "Load Character"});

    switch (choice)
    {
        case 1:
            roc::menu::character::create();
            break;
        case 2:
            roc::menu::character::load();
            break;
    }

    return 0;
}
