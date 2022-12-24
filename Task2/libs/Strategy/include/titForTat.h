#ifndef TASK2_TITFORTAT_H
#define TASK2_TITFORTAT_H

#include "strategy.h"

class TitForTat : public strategy::Strategy
{
public:
    TitForTat() = default;
    strategy::Move algorithm() override;
    void updateStrategyData(const std::array<strategy::Move, 2> results) override;

private:
    std::array<strategy::Move, 2> results = {strategy::C, strategy::C};
};

#endif // TASK2_TITFORTAT_H
