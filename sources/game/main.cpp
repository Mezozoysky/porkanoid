#include <pd/game/app.hpp>

// #ifdef __cplusplus
// extern "C"
// {
// #endif
int main(int argc, char ** argv)
{
    pd::game::App app;
    return app.run(argc, argv);
}
// #ifdef __cplusplus
// }
// #endif
