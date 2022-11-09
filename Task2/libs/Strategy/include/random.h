#ifndef COPY_MOVE_H
#define COPY_MOVE_H

#include "strategy.h"
#include <time.h>

class Random : public Strategy
{
public:
    Random();
    Move Algoritm() override;
};

int GetRandomNumber(int min, int max);

#endif