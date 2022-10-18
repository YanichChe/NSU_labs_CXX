#include "gameData.h"
#include "../../Strategy/include/strategy.h"

int GetPoint(int first, int second, int third)
{
    if (first == second == third == C)
    {
        return 7;
    }

    else if (first == second == C && first !=third)
    {
        return 3;
    }

    else if (first == C && first!= second && first != third)
    {
        return 0;
    }

    else if (first == D && first!= second && first != third)
    {
        return 9;
    }

    else if (first == second == D && first !=third)
    {
        return 5;
    }

    else
    {
        return 1;
    }
}

std::vector <int> GameData::GetTotalSums()
{
    return this->totalSums;
}

void GameData::ChangeTotalSum(int id, int points)
{
    this->totalSums[id] += points;
}

std::vector <std::vector <int>> GameData::GetMoves()
{
    return this->moves;
}

void GameData::AddMove(int id, int move)
{
   this->moves[id].push_back(move);
}

char GetMove(int move)
{
    if (move == C) return 'C';
    return 'D';
}

void PrintInfo( std::vector<std::vector <int>> moves, std::vector <int> totalSums)
{
    std::vector<int> movesFirst = moves[0];
    std::vector<int> movesSecond = moves[1];
    std::vector<int> movesThird = moves[2];

    std::cout << "1 2 3    1 2 3" << std::endl;

    for (int i = 0; i < movesFirst.size(); i++)
    {
        std::cout << GetMove(movesFirst[i]) << " " << GetMove(movesSecond[i]) << " " << GetMove(movesThird[i]);
        std::cout << " => ";
        std::cout << GetPoint(movesFirst[i], movesSecond[i], movesThird[i])
           << " " << GetPoint(movesSecond[i], movesFirst[i], movesThird[i])
           << " " << GetPoint(movesThird[i], movesSecond[i], movesFirst[i])
        << std::endl;
    }

    std::cout << "Total sum:" << std::endl;
    std::cout << totalSums[0] << std::endl;
    std::cout << totalSums[1] << std::endl;
    std::cout << totalSums[2] << std::endl;
}
