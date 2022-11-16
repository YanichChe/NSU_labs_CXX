#ifndef STRATEGY_FACTORY_H
#define STRATEGY_FACTORY_H

#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
#include "strategy.h"
#include "alwaysCooperate.h"
#include "alwaysDefect.h"
#include "titForTat.h"
#include "random.h"
#include "softGrudger.h"
#include "pavlov.h"
#include <exception>

class NotFoundStrategy : public std::invalid_argument
{
public:
    explicit NotFoundStrategy(const std::string &strategyName);
};

using StrategyPointer = std::unique_ptr<Strategy>;

class StrategyFactory
{
public:
    StrategyPointer createStrategy(std::string strategyName, std::string configs);
};

#endif
