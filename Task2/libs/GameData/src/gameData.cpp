#include "gameData.h"

std::vector<int> GameData::GetTotalSums()
{
    return this->totalSums;
}

void GameData::ChangeTotalSum(int id, int points)
{
    this->totalSums[id] += points;
}

Matrix *GameData::GetMatrix()
{
    return &(this->matrix);
}

int GetPoint(Move first, Move second, Move third)
{
    if (first == second == third == C)
    {
        return 7;
    }

    else if (first == second == C && first != third)
    {
        return 3;
    }

    else if (first == C && first != second && first != third)
    {
        return 0;
    }

    else if (first == D && first != second && first != third)
    {
        return 9;
    }

    else if (first == second == D && first != third)
    {
        return 5;
    }

    else
    {
        return 1;
    }
}
