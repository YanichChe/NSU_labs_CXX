#ifndef ALWAYS_COOPERATE
#define ALWAYS_COOPERATE

#include "strategy.h"
class AlwaysCooperate : public Strategy
{
public:
    AlwaysCooperate();
    Move Algoritm() override;
};

Strategy *CreateStrategy(GameData *data);

#endif