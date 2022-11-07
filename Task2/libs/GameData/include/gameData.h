#ifndef TASK2_GAMEDATA_H
#define TASK2_GAMEDATA_H

#include "../../Matrix/include/matrix.h"

class GameData
{
public:
    void SetStrategiesNames(std::vector<std::string> strategiesNames);
    void SetSteps(int steps);
    void SetConfigs(std::string configs);
    // void SetMatrix(std::string fileName);

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
