#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>

class GameData
{
public:
    std::vector <int> GetTotalSums();
    void ChangeTotalSum(int id, int points);
    std::vector<std::vector <Move>> GetMoves();
    void AddMove(int id, Move move);

private:
    std::vector<std::vector <Move>> moves;
    std::vector <int> totalSums;
};

void PrintInfo( std::vector<std::vector <Move>> moves, std::vector <int> totalSums);