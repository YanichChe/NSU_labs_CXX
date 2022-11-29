#include "game.h"

void Game::startGame(GameData *data, const std::string modeName)
{
    ModeFactory modeFactory;

    ModePointer mode;
    mode = modeFactory.create(modeName, data);

    mode->start();
}
