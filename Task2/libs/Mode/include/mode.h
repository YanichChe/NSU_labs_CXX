#ifndef MODE_H
#define MODE_H

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "strategyFactory.h"
#include "gameData.h"

class Mode
{
public:
    Mode(GameData *data);
    virtual ~Mode() = default;
    virtual std::array<int, PLAYERS_NUMBER> Start() = 0;
    std::array<Move, PLAYERS_NUMBER> GetVotes();
    void UpdateTotalSums(std::array<Move, PLAYERS_NUMBER> results);
    void UpdateStrategies(std::array<Move, PLAYERS_NUMBER> results);

protected:
    std::vector<std::string> strategyNames;
    int steps;
    std::string configs;
    Matrix matrix;

    std::array<StrategyPointer, 3> strategies;

    std::array<int, PLAYERS_NUMBER> totalSums = {0, 0, 0};
};

#endif