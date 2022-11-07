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

void GameData::SetStrategiesNames(std::vector<std::string> strategiesNames)
{
    this->strategiesNames = strategiesNames;
}

void GameData::SetSteps(int steps)
{
    this->steps = steps;
}

void GameData::SetConfigs(std::string configs)
{
    this->configs = configs;
}

/*void GameData::SetMatrix(std::string fileName)
{
    Matrix matrix(fileName);
    this->matrix = matrix;
}*/