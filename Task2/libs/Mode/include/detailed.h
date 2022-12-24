#ifndef DETAILED_MODE_H
#define DETAILED_MODE_H

#include "mode.h"
#include <iomanip>

const std::string QUIT = "quit";
const std::string STEP = "step";

class DetailedMode : public mode::Mode
{
public:
    DetailedMode(gameData::GameData *gameData);
    std::array<int, matrix::PLAYERS_NUMBER> start() override;

private:
    void printCurrentSums(const std::array<strategy::Move, matrix::PLAYERS_NUMBER> results);
};

#endif