#ifndef ALWAYS_COOPERATE_H
#define ALWAYS_COOPERATE_H

#include "strategy.h"
class AlwaysCooperate : public Strategy
{
public:
    AlwaysCooperate() = default;
    Move Algoritm() override;
};

#endif