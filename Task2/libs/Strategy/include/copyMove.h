#ifndef COPY_MOVE_H
#define COPY_MOVE_H

#include "strategy.h"

class CopyMove : public Strategy
{
public:
    CopyMove(GameData *data);
    Move Algoritm() override;

private:
    std::vector<std::vector<Move>> moves;
};

Strategy *CreateStrategy(GameData *data);

#endif