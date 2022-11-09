#include "gameData.h"

std::vector<std::string> GameData::GetStrategiesNames()
{
    return strategiesNames;
}
int GameData::GetSteps()
{
    return steps;
}

std::string GameData::GetConfigs()
{
    return configs;
}

Matrix GameData::GetMatrix()
{
    return matrix;
}

void GameData::SetStrategiesNames( std::vector<std::string> strategiesNames)
{
    this->strategiesNames = strategiesNames;
}

GameData::GameData(std::vector<std::string> strategiesNames, int steps, std::string configs, std::string matrixFileName)
{
    Matrix matrix(matrixFileName);
    this->matrix = matrix;
    this->strategiesNames = strategiesNames;
    this->steps = steps;
    this->configs = configs;
}