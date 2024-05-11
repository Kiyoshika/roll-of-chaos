#include "player.hpp"
#include "util.hpp"

roc::entity::Player::Player(const std::string& name)
{
    this->name = name;
    this->save_path = roc::util::get_game_data_path() + name + ".cfg";

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

    for (const auto& [skill, level] : skills)
        save << skill << "=" << std::to_string(level) << "\n";

    save.close();
}

const std::string& roc::entity::Player::get_save_path()
{
    return this->save_path;
}
