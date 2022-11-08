#include "gtest/gtest.h"
#include "modeFactory.h"

TEST(constructor_tests, fast)
{
    std::vector<std::string> strategiesNames = {"alwaysCooperate", "alwaysDesert", "random"};
    GameData data(strategiesNames, 5, "meow", "C:/Users/Yana228/LABS_NSU/Task2/libs/GameData/points.txt");

    ModeFactory modeFactory;
    ModePointer fast = modeFactory.Create("fast", &data);

    EXPECT_NO_THROW({fast->Start();});
}

TEST (mode_factory_tests, wrong_mode_name) {
    GameData data;
    ModeFactory factory;
    try
    {
        ModePointer mode = factory.Create("lalala", &data);
    }
    catch (const NotFoundMode& exception)
    {
        EXPECT_STREQ(exception.what(), "lalala not found mode");
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}