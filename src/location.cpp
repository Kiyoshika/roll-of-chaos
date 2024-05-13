#include "location.hpp"

roc::Location::Location(const std::string& name, const std::vector<std::string>& menu_options)
{
    this->name = name;
    this->menu_options = menu_options;
}

const std::string& roc::Location::get_name()
{
    return this->name;
}

const std::vector<std::string>& roc::Location::get_menu_options() const
{
    return this->menu_options;
}

std::unordered_map<std::string, roc::Location> roc::database::locations = {
    { "Gaya Village", roc::Location("Gaya Village", {
                "Character Sheet",
                "Save Game",
                "Alex's Weaponry",
                "Ooglog's Armory",
                "Ferrick's Magic",
                "Gaya Inn",
                "Travel to Outskirt Forest",
                "Travel to Dilapidated Plains"
            })
    }
};
