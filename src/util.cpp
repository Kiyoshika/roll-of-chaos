#include "util.hpp"

// unfortunately to "standard" way to get the home directory yet in C++...
std::string roc::util::get_home_dir()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        return std::string(std::getenv("HOMEDRIVE")) + std::string(std::getenv("HOMEPATH"));
    #else
        return std::string(std::getenv("HOME"));
    #endif 
}

std::string roc::util::get_game_data_path()
{
    return roc::util::get_home_dir() + "/roll-of-chaos/characters/";
}

std::string roc::util::get_filename(const std::string& path)
{
    size_t right_idx = path.size();
    while(right_idx --> 0) // size() - 1, size() - 2, ..., 0
    {
        if (path[right_idx] == '/' || path[right_idx] == '\\')
        {
            right_idx += 1;
            break;
        }
    }

    return path.substr(right_idx);
}
