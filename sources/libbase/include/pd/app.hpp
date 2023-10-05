#pragma once

#include "context.hpp"


namespace pd
{

class App
{
public:
    App();
    virtual ~App() = default;

    int run(int argc, char ** argv);

    void stop() noexcept;
    bool isStopping() const noexcept;

private:
    virtual int onConfigure() = 0;
    virtual int onStart() = 0;
    virtual void onStop() = 0;

private:
    bool mIsStopping;
};

inline void App::stop() noexcept
{
    mIsStopping = true;
}

inline bool App::isStopping() const noexcept
{
    return mIsStopping;
}

} // namespace pd

