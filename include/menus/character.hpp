#pragma once

namespace roc
{
// forward declaration
namespace entity { class Player; };

namespace menu
{
namespace character
{
    // create new character
    void create(roc::entity::Player& player);

    // roll a die for a skill when creating your character
    void roll_for_skill(uint8_t die_faces, roc::entity::Player& player);

    // load character
    void load(roc::entity::Player& player);
}; // namespace character
}; // namespace menu
}; // namespace roc
