#include "menus/menu.hpp"
#include "menus/character.hpp"
#include "draw.hpp"

void roc::menu::character::create()
{
    roc::draw::splash_text();

    std::string character_name = roc::menu::get_text_input("What is your name? (no spaces)");

    std::cout << "\n Is the name '" << character_name << "' correct?\n";
    uint16_t choice = roc::menu::choice_menu({"Yes", "No"});
    switch (choice)
    {
        case 1:
            break;
        case 2:
            return roc::menu::character::create();
            break;
    }


}

void roc::menu::character::load()
{

}
