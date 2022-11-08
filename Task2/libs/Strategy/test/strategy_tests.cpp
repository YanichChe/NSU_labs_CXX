#include "gtest/gtest.h"
#include "strategyFactory.h"

/*TEST (strategy_factory_tests, wrong_mode_name) {
    StrategyFactory strategyFactory;
    try
    {
        StrategyPointer strategyPointer = strategyFactory.createStrategy("oops", "");
    }
    catch (const NotFoundStrategy& exception)
    {
        EXPECT_STREQ(exception.what(), "oops not found strategy");
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

TEST(constructor_tests, random)
{
    StrategyFactory factory;
    StrategyPointer strategyRandom = factory.createStrategy("random", "");
    EXPECT_NO_THROW({strategyRandom->Algoritm();});
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}