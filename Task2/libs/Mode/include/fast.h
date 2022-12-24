#ifndef FAST_MODE_H
#define FAST_MODE_H

#include "mode.h"

class FastMode : public mode::Mode
{
public:
    FastMode(gameData::GameData *gameData);
    std::array<int, matrix::PLAYERS_NUMBER> start() override;

private:
    void printTotalSums();
};

#endif