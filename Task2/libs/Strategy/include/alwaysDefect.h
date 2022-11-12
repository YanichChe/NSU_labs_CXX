#ifndef ALWAYS_DEFECT_H
#define ALWAYS_DEFECT_H

#include "strategy.h"
class AlwaysDefect : public Strategy
{
public:
    AlwaysDefect() = default;
    Move Algoritm() override;
};

#endif