#include "gtest/gtest.h"
#include "gameData.h"

TEST(constructor_tests, game_data_constructor)
{
    std::vector<std::string> strategiesNames = {"alwaysCooperate", "alwaysDefect", "random"};
    GameData data(strategiesNames, 5, "meow", "C:/Users/Yana228/LABS_NSU/Task2/libs/GameData/points.txt");

    EXPECT_EQ(data.GetStrategiesNames()[0], "alwaysCooperate");
    EXPECT_EQ(data.GetSteps(), 5);
    EXPECT_EQ(data.GetConfigs(), "meow");

     Matrix matrix = data.GetMatrix();

     std::array<std::array<int, PLAYERS_NUMBER>, 8> points=
             {{
                      { 4, 4, 4 },
                      { 3, 3, 9 },
                      { 3, 9, 3 },
                      { 0, 5, 5 },
                      { 9, 3, 3 },
                      { 5, 0, 5 },
                      { 5, 5, 0 },
                      { 1, 1, 1 }
              }};

     std::array<std::array<int, PLAYERS_NUMBER>, 8> resultingMatrix = matrix.GetMatrix();

     const int row = 8, column = PLAYERS_NUMBER;

     for (int i = 0; i < row; i++)
         for (int j = 0; j < column; j++)
             EXPECT_EQ(points[i][j], resultingMatrix[i][j]);
}

TEST(constructor_tests, few_strategies_names)
{
    std::vector<std::string> strategiesNames = {"alwaysCooperate", "alwaysDefect"};

    try
    {
        GameData data(strategiesNames, 5, "meow", "C:/Users/Yana228/LABS_NSU/Task2/libs/GameData/points.txt");
    }
    catch (const StrategyCountException &exception)
    {
        EXPECT_STREQ(exception.what(), "2 - few strategies for game");
    }
}

TEST(constructor_tests, wrong_steps_value)
{
    std::vector<std::string> strategiesNames = {"alwaysCooperate", "alwaysDefect", "random"};

    try
    {
        GameData data(strategiesNames, 0, "meow", "C:/Users/Yana228/LABS_NSU/Task2/libs/GameData/points.txt");
    }
    catch (const WrongStepsValue &exception)
    {
        EXPECT_STREQ(exception.what(), "0 - wrong steps value");
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}