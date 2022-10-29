#include "gameData.h"

std::vector<int> GameData::GetTotalSums()
{
    return this->totalSums;
}

void GameData::ChangeTotalSum(int id, Move moves[])
{
    this->totalSums[id] += GetPoint(this->points, moves[0], moves[1], moves[2]);
}

Matrix *GameData::GetMatrix()
{
    return &(this->matrix);
}

int GetPoint(int points[], Move first, Move second, Move third)
{
    if (first == second == third == C)
    {
        return points[4];
    }

    else if (first == second == C && first != third)
    {
        return points[2];
    }

    else if (first == C && first != second && first != third)
    {
        return points[0];
    }

    else if (first == D && first != second && first != third)
    {
        return points[5];
    }

    else if (first == second == D && first != third)
    {
        return points[3];
    }

    else
    {
        return points[1];
    }
}

void GameData::ReadPoints()
{
    std::ifstream in(POINTS_FILE);

    for (int i = 0; i < POINTS_NUMBER; i++)
    {
        in >> this->points[i++];
    }

    in.close();
}