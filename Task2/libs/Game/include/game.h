#ifndef TASK2_GAME_H
#define TASK2_GAME_H
#include "gameData.h"
#include "modeFactory.h"

using namespace gameData;

class Game
{
public:
    void startGame(GameData *data, const std::string modeName);
};

#endif // TASK2_GAME_H
