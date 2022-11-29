#ifndef ALWAYS_COOPERATE_H
#define ALWAYS_COOPERATE_H

#include "strategy.h"

using namespace strategy;

class AlwaysCooperate : public Strategy
{
public:
    AlwaysCooperate(){};
    Move algorithm() override;
};

#endif