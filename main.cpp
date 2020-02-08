#include "RQ_Engine.h"
#include "src/Game.h"

using namespace RQEngine;

int main()
{
    Game game;
    game.Init();

    while (game.IsRunning()) {
        game.Process();
    }
    game.Quit();
    return EXIT_SUCCESS;
}
