#ifndef DETAILED_MODE_H
#define DETAILED_MODE_H

#include "mode.h"

class DetailedMode : public Mode
{
public:
    DetailedMode(GameData *gameData);
    void Start() override;
};

#endif