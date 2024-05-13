#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <functional>

namespace roc
{

// forward declaration
namespace entity { class Player; };

class Location
{
    public:
        Location() {}
        Location(
            const std::string& name,
            const std::vector<std::pair<std::string, std::function<void(roc::entity::Player&)>>>& menu_options);
        const std::string& get_name();
        const std::vector<std::pair<std::string, std::function<void(roc::entity::Player&)>>>& get_menu_options() const;
    private:
        std::string name;
        std::vector<std::pair<std::string, std::function<void(roc::entity::Player&)>>> menu_options;
}; // class Location

namespace database
{
    extern std::unordered_map<std::string, roc::Location> locations;
}; // namespace database
}; // namespace roc
