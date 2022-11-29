#ifndef TASK2_TOURNAMENT_H
#define TASK2_TOURNAMENT_H

#include "modeFactory.h"
#include <algorithm>

using namespace mode;
class TournamentMode : public Mode
{
public:
    TournamentMode(GameData *gameData);
    std::array<int, PLAYERS_NUMBER> start() override;

private:
    std::vector<int> allPoints;
    std::vector<std::array<std::string, PLAYERS_NUMBER>> combinations;
    void createCombinations(const std::vector<std::string> strategyNames);
    GameData *data;
    void updateTotalPoints(const std::string StrategyName, const int points);
    void printResults();
};

#endif // TASK2_TOURNAMENT_H
