#include "game.h"

void Game::StartGame(GameData *data, std::string modeName)
{
    ModeFactory modeFactory;
    ModePointer mode = modeFactory.Create(modeName, data);

    mode->Start();
}
