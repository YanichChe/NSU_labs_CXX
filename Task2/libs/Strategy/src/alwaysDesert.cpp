#include "alwaysDesert.h"

Move AlwaysDesert::Algoritm()
{
    return D;
}

Strategy *CreateStrategy(GameData *data)
{
    return new AlwaysDesert();
}