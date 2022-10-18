#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>

class GameData
{
public:
    std::vector <int> GetTotalSums();
    void ChangeTotalSum(int id, int points);
    std::vector<std::vector <int>> GetMoves();
    void AddMove(int id, int move);

private:
    std::vector<std::vector <int>> moves;
    std::vector <int> totalSums;
};

void PrintInfo( std::vector<std::vector <int>> moves, std::vector <int> totalSums);