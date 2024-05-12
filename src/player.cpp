#include "player.hpp"
#include "util.hpp"
#include "json.h"
#include <sstream>

roc::entity::Player::Player(const std::string& name)
{
    this->name = name;
    this->save_path = roc::util::get_game_data_path() + name + ".json";

    this->level = 1;
    this->health = 20.0;
    this->location = "Gaya Village";

    this->skills = {
        { "Agility", 0 },
        { "Attack", 0 },
        { "Black Magic", 0 },
        { "Dexterity", 0 },
        { "Enchanting", 0 },
        { "Enhancement", 0 },
        { "Precision", 0 },
        { "Strength", 0 },
        { "White Magic", 0 },
        { "Axe Affinity", 0 },
        { "Bow Affinity", 0 },
        { "Mace Affinity", 0 },
        { "Spear Affinity", 0 },
        { "Sword Affinity", 0 },
        { "Whip Affinity", 0 }
    };

    this->skill_descriptions = {
        { "Agility", "Improve chances of dodging, attacking twice and using items/changing equipment without ending your turn in combat" },
        { "Attack", "Increases critical strike chance dealing double damage" },
        { "Black Magic", "Proficiency in offensive magic to use higher level spells" },
        { "Dexterity", "Proficiency in dual wielding different weapons and used in other skills" },
        { "Enchanting", "Proficiency in enchantments to apply stronger buffs to equipment" },
        { "Enhancement", "Proficiency in sharpening weapons and reinforcing equipment providing damage and defense bonuses" },
        { "Precision", "Improve accuracy of attacks in combat" },
        { "Strength", "Allows use of heavier weapons such as greatswords, greatshields on other special items" },
        { "White Magic", "Proficiency in defensive magic to use higher level spells" },
        { "Axe Affinity", "Proficiency in axes providing damage buffs" },
        { "Bow Affinity", "Proficiency in bows providing damage buffs" },
        { "Mace Affinity", "Proficiency in maces providing damage buffs" },
        { "Spear Affinity", "Proficiency in spears providing damage buffs" },
        { "Sword Affinity", "Proficiency in swords providing damage buffs" },
        { "Whip Affinity", "Proficiency in whips providing damage buffs" }
    };
}

uint8_t roc::entity::Player::get_skill_level(const std::string& skill_name)
{
    return this->skills[this->__get_skill_index(skill_name)].second;
}

const std::string& roc::entity::Player::get_skill_description(const std::string& skill_name)
{
    return this->skill_descriptions[skill_name];
}

std::vector<std::string> roc::entity::Player::get_skill_list()
{
    std::vector<std::string> skill_list;
    for (const auto& [skill, value] : this->skills)
        skill_list.push_back(skill);

    return skill_list;
}

size_t roc::entity::Player::__get_skill_index(const std::string& skill_name)
{
    for (size_t i = 0; i < this->skills.size(); ++i)
        if (skill_name == this->skills[i].first)
            return i;

    // we are guaranteed to find the skill name so this is just to satisfy the compiler
    return 0;
}

void roc::entity::Player::increment_skill_level(size_t skill_idx, uint8_t value)
{
    this->skills[skill_idx].second += value;
}

void roc::entity::Player::save_data()
{
    std::ofstream save(this->save_path);

    json::jobject save_obj;
    save_obj["level"] = this->level;
    save_obj["health"] = this->health;
    save_obj["location"] = this->location;

    json::jobject skills_obj;
    for (const auto& [skill, level] : this->skills)
        skills_obj[skill] = level;

    save_obj["skills"] = skills_obj;

    save << (std::string)save_obj;

    save.close();
}

const std::string& roc::entity::Player::get_save_path()
{
    return this->save_path;
}

void roc::entity::Player::load_data(const std::string& character_path)
{
    std::ifstream load(character_path);
    if (!load.is_open())
        return;

    std::stringstream buffer;
    buffer << load.rdbuf();
    std::string json_str = buffer.str();

    roc::entity::Player player;

    json::jobject load_data = json::jobject::parse(json_str);

    player.set_level(std::stoul(load_data.get("level")));
    player.set_health(std::stod(load_data.get("health")));
    player.set_location(load_data.get("location"));

    for (const std::string& skill : player.get_skill_list())
    {
        json::jobject skills_obj = json::jobject::parse(load_data.get("skills"));
        player.set_skill_level(skill, std::stod(skills_obj.get(skill)));
    }

    load.close();
}

void roc::entity::Player::set_level(uint8_t level)
{
    this->level = level;
}

void roc::entity::Player::set_health(double health)
{
    this->health = health;
}

void roc::entity::Player::set_location(const std::string& location)
{
    this->location = location;
}

void roc::entity::Player::set_skill_level(const std::string& skill_name, uint8_t value)
{
    size_t skill_idx = this->__get_skill_index(skill_name);
    this->skills[skill_idx].second = value;
}

uint8_t roc::entity::Player::get_level()
{
    return this->level;
}

const std::string& roc::entity::Player::get_location()
{
    return this->location;
}

double roc::entity::Player::get_health()
{
    return this->health;
}
