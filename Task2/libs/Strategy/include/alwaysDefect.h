#ifndef ALWAYS_DEFECT_H
#define ALWAYS_DEFECT_H

#include "strategy.h"
using namespace strategy;

class AlwaysDefect : public Strategy
{
public:
    AlwaysDefect() = default;
    Move algorithm() override;
};

#endif