#ifndef FAST_MODE_H
#define FAST_MODE_H

#include "mode.h"

class FastMode : public Mode
{
public:
    FastMode(GameData *gameData);
    void Start() override;

private:
    void PrintTotalSums();
};

#endif