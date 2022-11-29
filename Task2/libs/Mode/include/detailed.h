#ifndef DETAILED_MODE_H
#define DETAILED_MODE_H

#include "mode.h"
#include <iomanip>
using namespace mode;

const std::string QUIT = "quit";
const std::string STEP = "step";

class DetailedMode : public Mode
{
public:
    DetailedMode(GameData *gameData);
    std::array<int, PLAYERS_NUMBER> start() override;

private:
    void printCurrentSums(const std::array<Move, PLAYERS_NUMBER> results);
};

#endif