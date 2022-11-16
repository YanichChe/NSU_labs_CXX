#include "strategyFactory.h"

NotFoundStrategy ::NotFoundStrategy(const std::string &strategyName) :
                                    std::invalid_argument(strategyName + " not found strategy"){}

StrategyPointer StrategyFactory::createStrategy(std::string strategyName, std::string configs)
{
    if (strategyName == "alwaysCooperate")      return std::make_unique<AlwaysCooperate>();
    else if (strategyName == "alwaysDefect")    return std::make_unique<AlwaysDefect>();
    else if (strategyName == "random")          return std::make_unique<Random>();
    else if (strategyName == "titForTat")       return std::make_unique<TitForTat>();
    else if (strategyName == "softGrudger")     return std::make_unique<SoftGrudger>();
    else if (strategyName == "pavlov")          return std::make_unique<Pavlov>(configs);
    else                                        throw NotFoundStrategy(strategyName);
}
