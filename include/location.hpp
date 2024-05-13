#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace roc
{
class Location
{
    public:
        Location() {}
        Location(const std::string& name, const std::vector<std::string>& menu_options);
        const std::string& get_name();
        const std::vector<std::string>& get_menu_options() const;
    private:
        std::string name;
        std::vector<std::string> menu_options;
}; // class Location

namespace database
{
    extern std::unordered_map<std::string, roc::Location> locations;
}; // namespace database
}; // namespace roc
