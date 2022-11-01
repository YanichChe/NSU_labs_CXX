#ifndef COPY_MOVE_H
#define COPY_MOVE_H

#include "strategy.h"

class CopyMove : public Strategy
{
public:
    CopyMove(std::string configs);
    Move Algoritm() override;

private:
    std::vector<std::vector<Move>> moves;
};

#endif