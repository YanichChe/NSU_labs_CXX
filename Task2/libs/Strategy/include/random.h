#ifndef COPY_MOVE_H
#define COPY_MOVE_H

#include "strategy.h"
#include <time.h>

class Random : public Strategy
{
public:
    Random() = default;
    Move Algoritm() override;

private:
    std::vector<std::vector<Move>> strategiesVotes;
};

int GetRandomNumber(int min, int max);

#endif