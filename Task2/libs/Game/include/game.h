#ifndef TASK2_GAME_H
#define TASK2_GAME_H
#include "../../GameData/include/gameData.h"
#include "../../Matrix/include/matrix.h"
#include "../../Mode/include/modeFactory.h"

class Game {
    void StartGame(GameData* data, std::string modeName);
};

#endif //TASK2_GAME_H
