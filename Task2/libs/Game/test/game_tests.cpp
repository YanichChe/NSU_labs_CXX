#include "gtest/gtest.h"
#include "game.h"

TEST(constructor_tests, fast_mode)
{
    std::vector<std::string> strategiesNames = {"alwaysCooperate", "alwaysDefect", "random"};
    GameData data(strategiesNames, 5, "meow", "C:/Users/Yana228/LABS_NSU/Task2/libs/GameData/points.txt");

    ModeFactory modeFactory;
    ModePointer fast = modeFactory.Create("fast", &data);

    EXPECT_NO_THROW({ fast->Start(); });
}

TEST(constructor_tests, tournament_mode)
{
    std::vector<std::string> strategiesNames = {"alwaysCooperate", "alwaysDefect", "random", "titForTat", "softGrudger", "pavlov"};
    GameData data(strategiesNames, 10, "C:/Users/Yana228/LABS_NSU/Task2/configFiles/", "C:/Users/Yana228/LABS_NSU/Task2/libs/GameData/points.txt");

    ModeFactory modeFactory;
    ModePointer tournament = modeFactory.Create("tournament", &data);

    EXPECT_NO_THROW({ tournament->Start(); });
}

TEST(mode_factory_tests, wrong_mode_name)
{
    GameData data;
    ModeFactory factory;
    try
    {
        ModePointer mode = factory.Create("lalala", &data);
    }
    catch (const NotFoundMode &exception)
    {
        EXPECT_STREQ(exception.what(), "lalala not found mode");
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}