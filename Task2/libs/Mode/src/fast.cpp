#include "fast.h"

FastMode::FastMode(GameData *gameData) : Mode(gameData) {}

std::array<int, PLAYERS_NUMBER> FastMode::start()
{
    for (int i = 0; i < steps; i++)
    {
        std::array<Move, PLAYERS_NUMBER> results = getVotes();
        updateStrategies(results);
        updateTotalSums(results);
    }

    printTotalSums();
    return totalSums;
}

void FastMode::printTotalSums()
{
    std::cout << "Total sums: " << std::endl;

    for (int i = 0; i < PLAYERS_NUMBER; i++)
    {
        std::cout << std::setw(20) << std::left << strategyNames[i] << " " << totalSums[i] << std::endl;
    }
}
