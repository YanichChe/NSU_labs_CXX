#ifndef TASK2_SOFTGRUDGER_H
#define TASK2_SOFTGRUDGER_H

#include "strategy.h"

const int MAX_PUNISHMENT_COUNT = 6;
using namespace strategy;

class SoftGrudger : public Strategy
{
public:
    SoftGrudger() = default;
    Move algorithm() override;
    void updateStrategyData(const std::array<Move, 2> results) override;

private:
    std::array<Move, 2> results = {C, C};
    std::array<Move, 6> punishment = {D, D, D, D, C, C};
    Move choice = C;
    int indexPunishment = -1;
};

#endif // TASK2_SOFTGRUDGER_H