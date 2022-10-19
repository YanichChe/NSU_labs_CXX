#include "alwaysCooperate.h"

Move AlwaysCooperate::Algoritm()
{
    return C;
}

Strategy *CreateStrategy(GameData *data)
{
    return new AlwaysCooperate();
}