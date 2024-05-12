#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <fstream>

namespace roc
{
namespace entity
{
class Player
{
    public:
    Player() {}
    Player(const std::string& name);

    std::vector<std::string> get_skill_list();

    uint8_t get_level();
    double get_health();
    const std::string& get_location();

    void set_level(uint8_t level);
    void set_health(double health);
    void set_location(const std::string& location);

    void set_skill_level(const std::string& skill_name, uint8_t value);
    uint8_t get_skill_level(const std::string& skill_name);
    const std::string& get_skill_description(const std::string& skill_name);
    void increment_skill_level(const std::string& skill_name, uint8_t value);
    void increment_skill_level(size_t skill_idx, uint8_t value);

    void save_data();
    void load_data(const std::string& character_path);
    const std::string& get_save_path();

    private:
    uint8_t level;
    double health;
    std::string location;

    std::string save_path;

    std::string name;

    std::vector<std::pair<std::string, uint8_t>> skills;
    std::unordered_map<std::string, std::string> skill_descriptions;

    size_t __get_skill_index(const std::string& skill_name);
}; // class Player
}; // namespace entity
}; // namespace roc
