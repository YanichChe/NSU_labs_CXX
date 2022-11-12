#ifndef TASK2_GAMEDATA_H
#define TASK2_GAMEDATA_H

#include "matrix.h"
#include <time.h>

const std::string MATRIX_FILE_PATH = "C:/Users/Yana228/LABS_NSU/Task2/libs/GameData/points.txt";

class StrategyCountException : public std::invalid_argument
{
public:
    explicit StrategyCountException(const std::vector<std::string> strategiesNames);
};

class WrongStepsValue : public std::invalid_argument
{
public:
    explicit WrongStepsValue(const int steps);
};

class GameData
{
public:
    GameData(){};
    GameData(std::vector<std::string> strategiesNames, int steps, std::string configs, std::string matrixFileName);

    std::vector<std::string> GetStrategiesNames();
    int GetSteps();
    std::string GetConfigs();
    Matrix GetMatrix();

    void SetStrategiesNames(std::vector<std::string> strategiesNames);

private:
    std::vector<std::string> strategiesNames;
    int steps;
    std::string configs;
    Matrix matrix;
};

#endif // TASK2_GAMEDATA_H
