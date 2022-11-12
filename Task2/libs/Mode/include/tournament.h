#ifndef TASK2_TOURNAMENT_H
#define TASK2_TOURNAMENT_H

#include "modeFactory.h"
#include <algorithm>

class TournamentMode : public Mode
{
public:
    TournamentMode(GameData *gameData);
    std::array<int, PLAYERS_NUMBER> Start() override;

private:
    std::vector<int> allPoints;
    std::vector<std::array<std::string, PLAYERS_NUMBER>> combinations;
    void CreateCombinations(std::vector<std::string> strategyNames);
    GameData *data;
    void UpdateTotalPoints(std::string StrategyName, int points);
    void PrintResults();
};

#endif // TASK2_TOURNAMENT_H
