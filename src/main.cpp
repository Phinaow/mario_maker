#include "../header/game.h"

int main()
{
    Game game;

    while(game.isWindowOpen())
    {
        game.processEvents();
        game.update();
        game.render();
    }

    return 0;
}