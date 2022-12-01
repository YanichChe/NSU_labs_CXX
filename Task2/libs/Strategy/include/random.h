#ifndef COPY_MOVE_H
#define COPY_MOVE_H

#include "strategy.h"
#include <time.h>

class Random : public strategy::Strategy
{
public:
    Random();
    strategy::Move algorithm() override;
};

#endif