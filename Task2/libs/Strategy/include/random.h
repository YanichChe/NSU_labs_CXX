#ifndef COPY_MOVE_H
#define COPY_MOVE_H

#include "strategy.h"
#include <time.h>
using namespace strategy;

class Random : public Strategy
{
public:
    Random();
    Move algorithm() override;
};

#endif