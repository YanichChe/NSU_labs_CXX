#ifndef MODE_FACTORY_H
#define MODE_FACTORY_H

#include <memory>
#include <string>

#include "mode.h"
#include "gameData.h"
#include "detailed.h"
#include "fast.h"


using ModePtr = std::unique_ptr<Mode>;

class ModeFactory
{
public:
    ModePtr Create(std::string & mode, GameData* data);
};

#endif