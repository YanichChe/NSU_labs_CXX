#ifndef TASK2_GAME_H
#define TASK2_GAME_H
#include "gameData.h"
#include "modeFactory.h"

class Game
{
public:
    void startGame(gameData::GameData *data, const std::string modeName);
};

#endif // TASK2_GAME_H
