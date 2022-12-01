#include "mode.h"

using namespace mode;

Mode::Mode(gameData::GameData *data)
{
    strategyNames = *data->getStrategiesNames();
    steps = data->getSteps();
    configs = data->getConfigs();
    matrix = *data->getMatrix();

    strategyFactory::StrategyFactory strategyFactory;

    for (int i = 0; i < strategyNames.size(); i++)
    {
        strategies[i] = strategyFactory.createStrategy(strategyNames[i], configs);
    }
}

const std::array<strategy::Move, matrix::PLAYERS_NUMBER> Mode::getVotes()
{
    std::array<strategy::Move, matrix::PLAYERS_NUMBER> results;

    for (int i = 0; i < matrix::PLAYERS_NUMBER; i++)
    {
        results[i] = strategies[i]->algorithm();
    }

    return results;
}

void Mode::updateTotalSums(std::array<strategy::Move, matrix::PLAYERS_NUMBER> results)
{
    std::array<int, matrix::PLAYERS_NUMBER> pointsArray = *matrix.getRow(results);
    for (int i = 0; i < matrix::PLAYERS_NUMBER; i++)
    {
        totalSums[i] += pointsArray[i];
    }
}

void Mode::updateStrategies(std::array<strategy::Move, 3> results)
{
    for (int i = 0; i < matrix::PLAYERS_NUMBER; i++)
    {
        std::array<strategy::Move, matrix::PLAYERS_NUMBER - 1> otherResults;
        int index = 0;
        for (int j = 0; j < matrix::PLAYERS_NUMBER; j++)
        {
            if (i != j) otherResults[index++] = results[j];
        }
        strategies[i]->updateStrategyData(otherResults);
    }
}
