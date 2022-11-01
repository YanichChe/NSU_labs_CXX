#include <cstdlib>
#ifndef STRATEGY_FACTORY_H
#define STRATEGY_FACTORY_H

#include <cstring>
#include <memory>
#include <string>
#include "strategy.h"
#include "alwaysCooperate.h"
#include "alwaysDesert.h"
#include "copyMove.h"

using StrategyPtr = std::unique_ptr<Strategy>;

class StrategyFactory
{
    public:
        StrategyPtr createStrategy(std::string strategyName, std::string configs);
};

#endif

 