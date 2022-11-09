#ifndef DETAILED_MODE_H
#define DETAILED_MODE_H

#include "mode.h"
#include <iomanip>

class DetailedMode : public Mode
{
public:
    DetailedMode(GameData *gameData);
    std::array<int, PLAYERS_NUMBER> Start() override;

private:
    void PrintCurrentSums(std::array<Move, PLAYERS_NUMBER> results);
};

#endif