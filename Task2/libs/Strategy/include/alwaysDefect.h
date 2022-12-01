#ifndef ALWAYS_DEFECT_H
#define ALWAYS_DEFECT_H

#include "strategy.h"

class AlwaysDefect : public strategy::Strategy
{
public:
    AlwaysDefect() = default;
    strategy::Move algorithm() override;
};

#endif