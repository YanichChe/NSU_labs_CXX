#ifndef COPY_MOVE
#define COPY_MOVE

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