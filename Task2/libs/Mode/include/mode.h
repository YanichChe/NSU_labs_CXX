#ifndef MODE_H
#define MODE_H
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "strategy.h"
#include "gameData.h"

class Mode
{
public:
    Mode();
    virtual ~Mode() = default;
    virtual void Start() = 0;

private:
    std::vector<std::string> strategyNames;
    int steps;
    std::string configs;
    Matrix matrix;
    int totalSums[3] = {0, 0, 0};
};

#endif