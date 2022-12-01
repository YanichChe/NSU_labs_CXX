#include "strategyFactory.h"

using namespace strategyFactory;

StrategyPointer StrategyFactory::createStrategy(const std::string strategyName, const std::string configs)
{
    if (strategyName == "alwaysCooperate")      return std::make_unique<AlwaysCooperate>();
    else if (strategyName == "alwaysDefect")    return std::make_unique<AlwaysDefect>();
    else if (strategyName == "random")          return std::make_unique<Random>();
    else if (strategyName == "titForTat")       return std::make_unique<TitForTat>();
    else if (strategyName == "softGrudger")     return std::make_unique<SoftGrudger>();
}
