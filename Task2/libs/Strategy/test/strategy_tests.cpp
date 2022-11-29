#include "gtest/gtest.h"
#include "../include/strategyFactory.h"

using namespace strategy;
TEST(constructor_tests, always_cooperate)
{
    StrategyFactory factory;
    StrategyPointer strategyCooperate = factory.createStrategy("alwaysCooperate", "qq");
    EXPECT_EQ(strategyCooperate->algorithm(), C);
}

TEST(constructor_tests, always_desert)
{
    StrategyFactory factory;
    StrategyPointer strategyDefect = factory.createStrategy("alwaysDefect", "qq");
    EXPECT_EQ(strategyDefect->algorithm(), D);
}

TEST(constructor_tests, random)
{
    StrategyFactory factory;
    StrategyPointer strategyRandom = factory.createStrategy("random", "q");
    EXPECT_NO_THROW({strategyRandom->algorithm();});
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}