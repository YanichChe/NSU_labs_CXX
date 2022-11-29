#ifndef FAST_MODE_H
#define FAST_MODE_H

#include "mode.h"
using namespace mode;

class FastMode : public Mode
{
public:
    FastMode(GameData *gameData);
    std::array<int, PLAYERS_NUMBER> start() override;

private:
    void printTotalSums();
};

#endif