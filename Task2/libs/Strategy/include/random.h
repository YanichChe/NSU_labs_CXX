#ifndef COPY_MOVE_H
#define COPY_MOVE_H

#include "strategy.h"

class CopyMove : public Strategy
{
public:
    CopyMove() = default;
    Move Algoritm() override;
    void UpdateStrategyData(std::array<Move, 2> results) override;

private:
    std::vector<std::vector<Move>> strategiesVotes;
};

#endif