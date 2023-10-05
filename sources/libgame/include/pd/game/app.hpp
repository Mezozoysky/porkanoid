#pragma once

#include <pd/app.hpp>


namespace pd::game
{

class App
: public pd::App
{
public:
    App() = default;
    virtual ~App() noexcept = default;

    virtual int onConfigure() override { return 0; }
    virtual int onStart() override;
    virtual void onStop() override {}
};

} // namespace pd::game
