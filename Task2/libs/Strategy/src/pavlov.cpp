#include "pavlov.h"

Move Pavlov::Algoritm()
{
    return strategy->Algoritm();
}

Pavlov ::Pavlov(std::string configs)
{
    StrategyFactory strategyFactory;
    strategy = strategyFactory.createStrategy("titForTat", configs);
}