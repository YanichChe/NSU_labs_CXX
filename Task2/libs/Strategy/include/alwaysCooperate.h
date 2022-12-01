#ifndef ALWAYS_COOPERATE_H
#define ALWAYS_COOPERATE_H

#include "strategy.h"

class AlwaysCooperate : public strategy::Strategy
{
public:
    AlwaysCooperate(){};
    strategy::Move algorithm() override;
};

#endif