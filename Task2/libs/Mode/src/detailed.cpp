#include "detailed.h"

DetailedMode::DetailedMode(GameData *gameData) : Mode(gameData) {}

void DetailedMode::PrintCurrentSums(std::array<Move, PLAYERS_NUMBER> results)
{
    std::array<int, PLAYERS_NUMBER> pointsArray = matrix.GetRow(results);

    std::cout << std::setw(20) << std::left << "NAME"
              << std::setw(20) << std::left << "CHOICE"
              << std::setw(20) << std::left << "POINTS"
              << std::setw(20) << std::left << "TOTAL SUM" << std::endl;

    for (int i=0; i< PLAYERS_NUMBER; i++)
    {
        std::cout << std::setw(20) << std::left << strategyNames[i]
                  << std::setw(20) << std::left << static_cast<Move>(Move(results[i]))
                  << std::setw(20) << std::left << pointsArray[i]
                  << std::setw(20) << std::left << totalSums[i]<< std::endl;
    }
}

std::array<int, PLAYERS_NUMBER> DetailedMode::Start()
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

            PrintCurrentSums(results);
        }
    }
}