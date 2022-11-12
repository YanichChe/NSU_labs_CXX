#ifndef MODE_FACTORY_H
#define MODE_FACTORY_H

#include <memory>
#include <string>

#include "mode.h"
#include "gameData.h"
#include "detailed.h"
#include "fast.h"
#include "tournament.h"
#include <exception>

class NotFoundMode : public std::invalid_argument
{
public:
    explicit NotFoundMode(const std::string &modeName);
};

using ModePointer = std::unique_ptr<Mode>;

class ModeFactory
{
public:
    ModePointer Create(std::string mode, GameData *data);
};

#endif