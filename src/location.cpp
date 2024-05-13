#include "location.hpp"
#include "menus/character.hpp"

roc::Location::Location(
    const std::string& name,
    const std::vector<std::pair<std::string, std::function<void(roc::entity::Player&)>>>& menu_options)
{
    this->name = name;
    this->menu_options = menu_options;
}

const std::string& roc::Location::get_name()
{
    return this->name;
}

const std::vector<std::pair<std::string, std::function<void(roc::entity::Player&)>>>& roc::Location::get_menu_options() const
{
    return this->menu_options;
}

std::unordered_map<std::string, roc::Location> roc::database::locations = {
    { "Gaya Village", roc::Location("Gaya Village", {
            { "Character Sheet", &roc::menu::character::sheet },
            { "Save Game", nullptr },
            { "Alex's Weaponry", nullptr },
            { "Ooglog's Armory", nullptr },
            { "Ferrick's Magic", nullptr },
            { "Gaya Inn", nullptr },
            { "Travel to Outskirt Forest", nullptr },
            { "Travel to Dilapidated Plains", nullptr }
            })
    }
};
