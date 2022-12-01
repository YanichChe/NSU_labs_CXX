#ifndef TASK2_TOURNAMENT_H
#define TASK2_TOURNAMENT_H

#include "modeFactory.h"
#include <algorithm>
using ModePointer = std::unique_ptr<mode::Mode>;

class TournamentMode : public mode::Mode
{
public:
    TournamentMode(gameData::GameData *gameData);
    std::array<int, matrix::PLAYERS_NUMBER> start() override;

private:
    std::vector<int> allPoints;
    std::vector<std::array<std::string, matrix::PLAYERS_NUMBER>> combinations;
    void createCombinations(const std::vector<std::string> strategyNames);
    gameData::GameData *data;
    void updateTotalPoints(const std::string StrategyName, const int points);
    void printResults();
};

#endif // TASK2_TOURNAMENT_H
