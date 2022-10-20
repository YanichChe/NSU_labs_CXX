#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include "../../Matrix/include/matrix.h"

class GameData
{
public:
    std::vector<int> GetTotalSums();
    void ChangeTotalSum(int id, int points);
    Matrix *GetMatrix();

private:
    std::vector<int> totalSums;
    Matrix matrix;
};

#endif