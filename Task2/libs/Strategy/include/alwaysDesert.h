#ifndef ALWAYS_DESERT_H
#define ALWAYS_DESERT_H

#include "strategy.h"
class AlwaysDesert : public Strategy
{
public:
    AlwaysDesert() = default;
    Move Algoritm() override;
};

#endif