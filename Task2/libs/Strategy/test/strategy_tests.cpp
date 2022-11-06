#include "gtest/gtest.h"
#include "../include/strategyFactory.h"

/*TEST (constructor_tests, wrong_strategy_name) {
    StrategyFactory factory;
    try
    {
        StrategyPointer  strategyDesert = factory.createStrategy("LaLaLend", "");
    }
    catch (const NotFoundStrategyException& exception)
    {
        EXPECT_EQ(exception.what(), "LaLaLend not found strategy");
    }

}*/

TEST(constructor_tests, always_cooperate)
{
    StrategyFactory factory;
    StrategyPointer strategyCooperate = factory.createStrategy("alwaysCooperate", "");
    EXPECT_EQ(strategyCooperate->Algoritm(), C);
    StrategyPointer strategyDesert = factory.createStrategy("alwaysDesert", "");
}

TEST(constructor_tests, always_desert)
{
    StrategyFactory factory;
    StrategyPointer strategyDesert = factory.createStrategy("alwaysDesert", "");
    EXPECT_EQ(strategyDesert->Algoritm(), D);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}