#ifndef STRATEGY
#define STRATEGY

#include <stdlib.h>
#include <vector>
#include "../../GameData/include/gameData.h"

class Strategy
{
public:
    virtual Move Algoritm() = 0;
};

#endif
