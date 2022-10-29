#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "../../Matrix/include/matrix.h"
#define POINTS_FILE "points.txt"
#define POINTS_NUMBER 6
#define PLAYERS_NUMBER 3
class GameData
{
public:
    std::vector<int> GetTotalSums();
    void ChangeTotalSum(int id, Move moves[PLAYERS_NUMBER]);
    Matrix *GetMatrix();
    void ReadPoints();

private:
    std::vector<int> totalSums;
    Matrix matrix;
    int points[POINTS_NUMBER];
};


int GetPoint(int points [], Move first, Move second, Move third);

#endif