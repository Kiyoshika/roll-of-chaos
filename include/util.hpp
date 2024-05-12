#pragma once

#include <string>
#include <cstdlib>

namespace roc
{
namespace util
{
    std::string get_home_dir();
    std::string get_game_data_path();
    std::string get_filename(const std::string& path);
}; // namespace util
}; // namespace roc
