#include "tournament.h"

TournamentMode::TournamentMode(GameData *gameData) : Mode(gameData)
{
    for (int i = 0; i < strategyNames.size(); i++)
    {
        allPoints.push_back(0);
    }
    this->data = gameData;
};

void TournamentMode::CreateCombinations(std::vector<std::string> strategyNames)
{
    int strategyCount = strategyNames.size();
    std::vector<bool> combinations(strategyCount);
    std::fill(combinations.begin(), combinations.begin() + PLAYERS_NUMBER, true);

    do
    {
        std::array<std::string, PLAYERS_NUMBER> combination;
        int index = 0;
        for (int i = 0; i < strategyCount; ++i)
        {
            if (combinations[i])
            {
                combination[index++] = strategyNames[i];
            }
        }
        this->combinations.push_back(combination);
    } while (std::prev_permutation(combinations.begin(), combinations.end()));
}

void TournamentMode::UpdateTotalPoints(std::string strategyName, int points)
{
    for (int i = 0; i < strategyNames.size(); i++)
    {
        if (strategyName == strategyNames[i])
        {
            allPoints[i] += points;
            break;
        }
    }
}

void TournamentMode::PrintResults()
{
    std::cout << "---------------------------------" << std::endl;
    std::cout << "RESULTS: " << std::endl;
    std::vector<std::string> winners;
    int max = allPoints[0];

    for (int i = 1; i < strategyNames.size(); i++)
    {
        if (allPoints[i] > max)
            max = allPoints[i];
    }

    for (int i = 0; i < strategyNames.size(); i++)
    {
        std::cout << std::setw(20) << std::left << strategyNames[i] << " " << allPoints[i] << std::endl;
        if (allPoints[i] == max)
            winners.push_back(strategyNames[i]);
    }

    std::cout << "---------------------------------" << std::endl;
    std::cout << "WINNERS: " << std::endl;

    for (int i = 0; i < winners.size(); i++)
    {
        std::cout << winners[i] << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;
}

std::array<int, PLAYERS_NUMBER> TournamentMode::Start()
{
    CreateCombinations(strategyNames);

    for (int i = 0; i < combinations.size(); i++)
    {
        std::cout << "----------- ROUND " << i + 1 << " -----------" << std::endl;
        std::vector<std::string> currentStrategiesNames = {combinations[i][0], combinations[i][1], combinations[i][2]};
        data->SetStrategiesNames(currentStrategiesNames);

        ModeFactory modeFactory;
        ModePointer fast = modeFactory.Create("fast", data);

        std::array<int, PLAYERS_NUMBER> currentPoints = fast->Start();
        for (int j = 0; j < PLAYERS_NUMBER; j++)
        {
            UpdateTotalPoints(currentStrategiesNames[j], currentPoints[j]);
        }
    }

    PrintResults();
}