#include "gtest/gtest.h"
#include "game.h"

TEST(constructor_tests, fast_mode)
{
    std::vector<std::string> strategiesNames = {"alwaysCooperate", "alwaysDefect", "random"};
    gameData::GameData data(strategiesNames, 5, "meow", "points.txt");

    modeFactory::ModeFactory modeFactory;
    ModePointer fast = modeFactory.create("fast", &data);

    EXPECT_NO_THROW({ fast->start(); });
}

TEST(constructor_tests, tournament_mode)
{
    std::vector<std::string> strategiesNames = {"alwaysCooperate", "alwaysDefect", "random", "titForTat", "softGrudger"};
    gameData::GameData data(strategiesNames, 10, "../../../configFiles/", "points.txt");

    modeFactory::ModeFactory modeFactory;
    ModePointer tournament = modeFactory.create("tournament", &data);

    EXPECT_NO_THROW({ tournament->start(); });
}

TEST(mode_factory_tests, wrong_mode_name)
{
    gameData::GameData data;
    modeFactory::ModeFactory factory;
    try
    {
        ModePointer mode = factory.create("lalala", &data);
    }
    catch (const modeFactory::NotFoundMode &exception)
    {
        EXPECT_STREQ(exception.what(), "lalala not found mode");
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}