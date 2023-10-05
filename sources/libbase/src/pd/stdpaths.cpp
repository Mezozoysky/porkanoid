#include <pd/stdpaths.hpp>
#include <SFML/Config.hpp>
#include <filesystem>
#if defined(SFML_SYSTEM_LINUX)
#include <unistd.h>
#endif

namespace fs = std::filesystem;


namespace pd::stdpaths
{

fs::path getExecutablePath() noexcept
{
    fs::path result;

#if defined(SFML_SYSTEM_LINUX)
    char pathBuffer[4096];
    ::ssize_t length = ::readlink("/proc/self/exe", pathBuffer, sizeof(pathBuffer) - 1u);
    if (length != -1)
    {
        pathBuffer[length] = '\0';
        result.assign(pathBuffer);
    }

#elif defined(SFML_SYSTEM_DARWIN)
#elif defined(SFML_SYSTEM_WINDOWS)
#endif

    return result;
}

} // namespace pd::stdpaths
