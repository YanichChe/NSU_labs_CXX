#ifndef TASK2_GAMEDATA_H
#define TASK2_GAMEDATA_H

#include "matrix.h"
#include <time.h>

#define MATRIX_FILE_PATH "C:/Users/Yana228/LABS_NSU/Task2/libs/GameData/points.txt"

class GameData
{
public:
    GameData(){};
    GameData(std::vector <std::string> strategiesNames, int steps, std::string configs, std::string matrixFileName);

    std::vector<std::string> GetStrategiesNames();
    int GetSteps();
    std::string GetConfigs();
    Matrix GetMatrix();

private:
    std::vector<std::string> strategiesNames;
    int steps;
    std::string configs;
    Matrix matrix;
};

#endif // TASK2_GAMEDATA_H
