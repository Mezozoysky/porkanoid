#include <pd/app.hpp>
#include <pd/stdpaths.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include <string_view>


namespace fs = std::filesystem;

using namespace std::literals;


namespace pd
{

App::App()
: mIsStopping{false}
{
}

int App::run(int argc, char ** argv)
{
    int error = 0;

    // initialize

    if (!error)
    {
        std::vector<std::string_view> args;
        for (int idx = 0; idx < argc; ++idx)
        {
            args.emplace_back(argv[idx]);
        }

        fs::path configPath;
        for (std::size_t idx = 0u; idx < args.size(); ++idx)
        {
            if (args[idx] == "--config"sv)
            {
                ++idx;
                if (idx >= args.size())
                {
                    // error = 2; // should ignore that error?
                    // logger->error("config path must follow '--config' option");
                }
                else
                {
                    try {
                        configPath.assign(args[idx]);
                    }  catch (std::exception & exc) {
                        // error = 2; // should ignore that error?
                        // logger->error("failed to parse config path from '{}' cmdline argument", args[idx]);
                    }
                }
            }
        }

        if (!error && configPath.empty())
        {
            configPath = stdpaths::getExecutablePath();
        }

        // read/handle config

        if (!error)
        {
            error = onConfigure();
        }
    }

    if (!error)
    {
        // setup, etc. AKA start

        if (!error)
        {
            error = onStart();
        }
    }

    sf::RenderWindow window{sf::VideoMode{{1280u, 720u}, 32u}, {"PD"}};

    if (error)
    {
        stop();
    }

    while (!isStopping()  && window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                stop();
                break;
            default:
                // do nothing
                break;
            }
        }
    }

    if (window.isOpen())
    {
        window.close();
    }

    onStop();

    // shutdown, etc. AKA stop

    // terminate

    return error;
}

} // namespace pd
