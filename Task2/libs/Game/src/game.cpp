#include "game.h"

void Game::startGame(gameData::GameData *data, const std::string modeName)
{
    modeFactory::ModeFactory modeFactory;

    ModePointer mode;
    mode = modeFactory.create(modeName, data);

    mode->start();
}
