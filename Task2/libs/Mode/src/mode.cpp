#include "mode.h"

Mode::Mode(GameData *data)
{
    strategyNames = data->GetStrategiesNames();
    steps = data->GetSteps();
    configs = data->GetConfigs();
    matrix = data->GetMatrix();

    StrategyFactory strategyFactory;

    for (int i = 0; i < strategyNames.size(); i++)
    {
        strategies[i] = strategyFactory.createStrategy(strategyNames[i], configs);
    }
}

std::array<Move, PLAYERS_NUMBER> Mode::GetVotes()
{
    std::array<Move, PLAYERS_NUMBER> results;

    for (int i = 0; i < PLAYERS_NUMBER; i++)
    {
        results[i] = strategies[i]->Algoritm();
    }

    return results;
}

void Mode::UpdateTotalSums(std::array<Move, PLAYERS_NUMBER> results)
{
    std::array<int, PLAYERS_NUMBER> pointsArray = matrix.GetRow(results);
    for (int i = 0; i < PLAYERS_NUMBER; i++)
    {
        totalSums[i] += pointsArray[i];
    }
}

void Mode::UpdateStrategies(std::array<Move, 3> results)
{
    for (int i = 0; i < PLAYERS_NUMBER; i++)
    {
        std::array<Move, PLAYERS_NUMBER - 1> otherResults;
        int index = 0;
        for (int j = 0; j < PLAYERS_NUMBER; j++)
        {
            if (i != j)
            {
                otherResults[index++] = results[j];
            }
        }
        strategies[i]->UpdateStrategyData(otherResults);
    }
}
