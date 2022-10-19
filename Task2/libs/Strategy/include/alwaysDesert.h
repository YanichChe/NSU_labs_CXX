#ifndef ALWAYS_DESERT
#define ALWAYS_DESERT

#include "strategy.h"
class AlwaysDesert : public Strategy
{
public:
    AlwaysDesert();
    Move Algoritm() override;
};

Strategy *CreateStrategy(GameData *data);

#endif