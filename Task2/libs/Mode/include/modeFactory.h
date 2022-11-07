#ifndef MODE_FACTORY_H
#define MODE_FACTORY_H

#include <memory>
#include <string>

#include "mode.h"
#include "../../GameData/include/gameData.h"
#include "detailed.h"
#include "fast.h"

using ModePointer = std::unique_ptr<Mode>;

class ModeFactory
{
public:
    ModePointer Create(std::string &mode, GameData *data);
};

#endif