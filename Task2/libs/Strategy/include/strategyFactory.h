#ifndef STRATEGY_FACTORY_H
#define STRATEGY_FACTORY_H

#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
#include "strategy.h"
#include "alwaysCooperate.h"
#include "alwaysDesert.h"
#include "random.h"

using StrategyPointer = std::unique_ptr<Strategy>;

class StrategyFactory
{
public:
    StrategyPointer createStrategy(std::string strategyName, std::string configs);
};

#endif
