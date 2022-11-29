#ifndef TASK2_TITFORTAT_H
#define TASK2_TITFORTAT_H

#include "strategy.h"
using namespace strategy;

class TitForTat : public Strategy
{
public:
    TitForTat() = default;
    Move algorithm() override;
    void updateStrategyData(const std::array<Move, 2> results) override;

private:
    std::array<Move, 2> results = {C, C};
};

#endif // TASK2_TITFORTAT_H
