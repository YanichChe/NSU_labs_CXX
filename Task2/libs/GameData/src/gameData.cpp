#include "gameData.h"
using namespace gameData;

StrategyCountException ::StrategyCountException(const std::vector<std::string> strategiesNames) : std::invalid_argument(std::to_string(strategiesNames.size()) + " - few strategies for game") {}

WrongStepsValue ::WrongStepsValue(const int steps) : std::invalid_argument(std::to_string(steps) + " - wrong steps value") {}

const std::vector<std::string>* GameData::getStrategiesNames()
{
    return &strategiesNames;
}
const int GameData::getSteps()
{
    return steps;
}

const std::string GameData::getConfigs()
{
    return configs;
}

const Matrix* GameData::getMatrix()
{
    return &matrix;
}

void GameData::setStrategiesNames(const std::vector<std::string> strategiesNames)
{
    this->strategiesNames = strategiesNames;
}

GameData::GameData(std::vector<std::string> strategiesNames, int steps, std::string configs, std::string matrixFileName)
{
    if (strategiesNames.size() < PLAYERS_NUMBER)
    {
        throw StrategyCountException(strategiesNames);
    }

    if (steps < 1)
    {
        throw WrongStepsValue(steps);
    }

    Matrix matrix(matrixFileName);
    this->matrix = matrix;

    this->strategiesNames = strategiesNames;
    this->steps = steps;
    this->configs = configs;
}