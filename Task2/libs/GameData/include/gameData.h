//
// Created by Yana228 on 03.11.2022.
//

#ifndef TASK2_GAMEDATA_H
#define TASK2_GAMEDATA_H

#include "matrix.h"

#define PLAYERS_NUMBER 3
class GameData
{
public:
    GameData();
    ~GameData();

    void SetStrategiesNames(std::vector<std::string> names);
    void SetSteps(int steps);
    void SetConfigs(std::string configs);
    void SetMatrix(Matrix *matrix);

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

#endif //TASK2_GAMEDATA_H
