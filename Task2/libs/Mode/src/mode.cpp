#include "mode.h"

using namespace mode;

Mode::Mode(GameData *data)
{
    strategyNames = *data->getStrategiesNames();
    steps = data->getSteps();
    configs = data->getConfigs();
    matrix = *data->getMatrix();

    StrategyFactory strategyFactory;

    for (int i = 0; i < strategyNames.size(); i++)
    {
        strategies[i] = strategyFactory.createStrategy(strategyNames[i], configs);
    }
}

const std::array<Move, PLAYERS_NUMBER> Mode::getVotes()
{
    std::array<Move, PLAYERS_NUMBER> results;

    for (int i = 0; i < PLAYERS_NUMBER; i++)
    {
        results[i] = strategies[i]->algorithm();
    }

    return results;
}

void Mode::updateTotalSums(std::array<Move, PLAYERS_NUMBER> results)
{
    std::array<int, PLAYERS_NUMBER> pointsArray = *matrix.getRow(results);
    for (int i = 0; i < PLAYERS_NUMBER; i++)
    {
        totalSums[i] += pointsArray[i];
    }
}

void Mode::updateStrategies(std::array<Move, 3> results)
{
    for (int i = 0; i < PLAYERS_NUMBER; i++)
    {
        std::array<Move, PLAYERS_NUMBER - 1> otherResults;
        int index = 0;
        for (int j = 0; j < PLAYERS_NUMBER; j++)
        {
            if (i != j) otherResults[index++] = results[j];
        }
        strategies[i]->updateStrategyData(otherResults);
    }
}
