#include <pd/game/app.hpp>
#include <pd/stdpaths.hpp>
#include <filesystem>
#include <iostream>


namespace fs = std::filesystem;

namespace pd::game
{

int App::onStart()
{
    fs::path execPath = stdpaths::getExecutablePath();
    std::cout << "Executable path: '" << execPath.string() << "';" << std::endl;
    return 0;
}

} // namespace pd::game
