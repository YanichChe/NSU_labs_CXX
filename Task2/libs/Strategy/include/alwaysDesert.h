#ifndef ALWAYS_DESERT_H
#define ALWAYS_DESERT_H

#include "strategy.h"
class AlwaysDesert : public Strategy
{
public:
    AlwaysDesert();
    Move Algoritm() override;
};

Strategy *CreateStrategy(GameData *data);

#endif