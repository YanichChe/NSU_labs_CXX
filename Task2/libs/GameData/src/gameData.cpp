#include "gameData.h"

void GameData::SetStrategiesNames(std::vector<std::string> names)
{
    this->strategiesNames = names;
}

void GameData::SetSteps(int steps)
{
    this->steps = steps;
}

void GameData::SetConfigs(std::string configs)
{
    this->configs = configs;
}

void GameData::SetMatrix(Matrix *matrix)
{
    this->matrix = *matrix;
}

std::vector<std::string> GameData::GetStrategiesNames()
{
    return this->strategiesNames;
}

int GameData::GetSteps()
{
    return this->steps;
}

std::string GameData::GetConfigs()
{
    return this->configs;
}

Matrix GameData::GetMatrix()
{
    return this->matrix;
}