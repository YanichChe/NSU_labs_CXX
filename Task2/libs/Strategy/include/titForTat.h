#ifndef TASK2_TITFORTAT_H
#define TASK2_TITFORTAT_H

#include "strategy.h"

class TitForTat : public Strategy
{
public:
    TitForTat() = default;
    Move Algoritm() override;
    void UpdateStrategyData(std::array<Move, 2> results) override;

private:
    std::array<Move, 2> results = {C, C};
};

#endif // TASK2_TITFORTAT_H
