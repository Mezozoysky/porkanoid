#pragma once

#include <filesystem>

namespace pd::stdpaths
{

std::filesystem::path getExecutablePath() noexcept;

} // pd::stdpaths
