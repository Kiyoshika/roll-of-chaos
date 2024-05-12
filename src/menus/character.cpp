#include "menus/menu.hpp"
#include "menus/character.hpp"
#include "draw.hpp"
#include "player.hpp"
#include "util.hpp"

#include <random>
#include <filesystem>

roc::entity::Player roc::menu::character::create()
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

    roc::entity::Player player(character_name);

    std::cout << "\n How would you like to roll for your stats? (you can roll multiple dice in the same skill)\n";
    choice = roc::menu::choice_menu({"1d20 in one skill", "1d8 in two skills", "1d6 in three skills", "1d4 in four skills"});
    switch (choice)
    {
        case 1:
            roc::menu::character::roll_for_skill(20, player);
            break;
        case 2:
            roc::menu::character::roll_for_skill(8, player);
            roc::menu::character::roll_for_skill(8, player);
            break;
        case 3:
            roc::menu::character::roll_for_skill(6, player);
            roc::menu::character::roll_for_skill(6, player);
            roc::menu::character::roll_for_skill(6, player);
            break;
        case 4:
            roc::menu::character::roll_for_skill(4, player);
            roc::menu::character::roll_for_skill(4, player);
            roc::menu::character::roll_for_skill(4, player);
            roc::menu::character::roll_for_skill(4, player);
            break;
    }

    std::filesystem::create_directories(roc::util::get_game_data_path());
    player.save_data();

    std::cout << "\n Below are your final skills. Your character data has been saved to " << player.get_save_path() << "\n";

    std::vector<std::string> skill_list = player.get_skill_list();
    for (std::string& skill : skill_list)
        skill += (" (" + std::to_string(player.get_skill_level(skill)) + ")");
    roc::draw::dialog(skill_list);

    std::cout << "\n";

    roc::menu::choice_menu({"Play Game"});

    return player;
}

void roc::menu::character::roll_for_skill(uint8_t die_faces, roc::entity::Player& player)
{
    roc::draw::splash_text();

    std::cout << "\n SKILL DESCRIPTIONS:\n";
    for (const std::string& skill : player.get_skill_list())
        std::cout << " " << skill << ": " << player.get_skill_description(skill) << "\n";
    std::cout << "\n";

    // for some reason the stream doesn't work with die_faces unless it's converted to a string
    // maybe some unsigned quirk?
    std::cout << "\n Please select a skill to roll a 1d" << std::to_string(die_faces) << " for:\n";
    std::vector<std::string> skill_list = player.get_skill_list();
    for (std::string& skill : skill_list)
        skill += (" (" + std::to_string(player.get_skill_level(skill)) + ")");

    uint16_t choice = roc::menu::choice_menu(skill_list);
    size_t skill_idx = choice - 1;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> die(1, die_faces);
    player.increment_skill_level(skill_idx, die(gen));

}

roc::entity::Player roc::menu::character::load()
{

    std::string data_path = roc::util::get_game_data_path();
    std::vector<std::string> character_names;
    std::vector<std::string> character_paths;

    roc::entity::Player player;

    for (const auto& entry : std::filesystem::directory_iterator(data_path))
    {
        std::string path = entry.path();
        character_paths.push_back(path);

        std::string character_name = roc::util::get_filename(path);
        character_name.erase(character_name.find(".json"));
        character_names.push_back(character_name);
    }

    if (character_names.size() == 0)
    {
        std::cout << " There are no saved characters...\n";
        uint16_t choice = roc::menu::choice_menu({"Create New Character"});
        if (choice == 1)
            player = roc::menu::character::create();
    }
    else
    {
        std::cout << " Please select a character to load:\n";
        uint16_t choice = roc::menu::choice_menu(character_names);
        choice -= 1; // convert choice to index

        player.load_data(character_paths[choice]);
    }

    return player;
}
