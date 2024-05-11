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
    Player(const std::string& name);

    std::vector<std::string> get_skill_list();

    uint8_t get_skill_level(const std::string& skill_name);
    const std::string& get_skill_description(const std::string& skill_name);
    void increment_skill_level(const std::string& skill_name, uint8_t value);
    void increment_skill_level(size_t skill_idx, uint8_t value);

    void save_data();
    const std::string& get_save_path();

    private:
    std::string save_path;
    std::string name;
    std::vector<std::pair<std::string, uint8_t>> skills;
    std::unordered_map<std::string, std::string> skill_descriptions;
    size_t __get_skill_index(const std::string& skill_name);
}; // class Player
}; // namespace entity
}; // namespace roc
