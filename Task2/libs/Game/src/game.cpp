#include "game.h"

void Game::StartGame(GameData *data, std::string modeName)
{
    ModeFactory modeFactory;

    ModePointer mode;
    try
    {
        mode = modeFactory.Create(modeName, data);
    }

    catch (const NotFoundStrategy &exception)
    {
        std::cout << exception.what() << std::endl;
        return;
    }

    mode->Start();
}
