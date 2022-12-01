#ifndef TASK2_SOFTGRUDGER_H
#define TASK2_SOFTGRUDGER_H

#include "strategy.h"

const int MAX_PUNISHMENT_COUNT = 6;

class SoftGrudger : public strategy::Strategy
{
public:
    SoftGrudger() = default;
    strategy::Move algorithm() override;
    void updateStrategyData(const std::array<strategy::Move, 2> results) override;

private:
    std::array<strategy::Move, 2> results = {strategy::C, strategy::C};
    std::array<strategy::Move, 6> punishment = {strategy::D, strategy::D, strategy::D, strategy::D, strategy::C, strategy::C};
    strategy::Move choice = strategy::C;
    int indexPunishment = -1;
};

#endif // TASK2_SOFTGRUDGER_H
