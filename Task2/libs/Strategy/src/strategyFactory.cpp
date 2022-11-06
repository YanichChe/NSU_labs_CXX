#include "strategyFactory.h"

StrategyPointer StrategyFactory::createStrategy(std::string strategyName, std::string configs)
{
    if (strategyName == "alwaysCooperate")
        return std::make_unique<AlwaysCooperate>();
    else if (strategyName == "alwaysDesert")
        return std::make_unique<AlwaysDesert>();
    else if (strategyName == "random")
        return std::make_unique<Random>();
}
