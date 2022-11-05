#include "fast.h"

FastMode::FastMode(GameData *gameData) : Mode(gameData) {}

void FastMode::Start()
{
    for (int i = 0; i < steps; i++)
    {
        std::array<Move, PLAYERS_NUMBER> results = GetVotes();
        UpdateStrategies(results);
        UpdateTotalSums(results);
    }

    PrintTotalSums();
}

void FastMode::PrintTotalSums()
{
    std::cout << "Total sums: " << std::endl;
    std::cout << "First: " << totalSums[0] << std::endl;
    std::cout << "Second: " << totalSums[0] << std::endl;
    std::cout << "Third: " << totalSums[0] << std::endl;
}
