#include "detailed.h"

DetailedMode::DetailedMode(GameData *gameData) : Mode(gameData) {}

void DetailedMode::PrintTotalSums()
{
    std::cout << "Total sums: " << std::endl;
    std::cout << "First: " << totalSums[0] << std::endl;
    std::cout << "Second: " << totalSums[0] << std::endl;
    std::cout << "Third: " << totalSums[0] << std::endl;
}

void DetailedMode::Start()
{
    while (true)
    {
        std::string input;
        std::cin >> input;

        if (input == "quit")
        {
            break;
        }
        else if (input == "step")
        {
            std::array<Move, PLAYERS_NUMBER> results = GetVotes();
            UpdateStrategies(results);
            UpdateTotalSums(results);
            PrintTotalSums();
        }
    }
}