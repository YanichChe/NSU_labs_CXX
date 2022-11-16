#include "modeFactory.h"

NotFoundMode ::NotFoundMode(const std::string &mode) :
                            std::invalid_argument(mode + " not found mode") {}

ModePointer ModeFactory::Create(std::string mode, GameData *data)
{
    if (mode == "detailed")         return std::make_unique<DetailedMode>(data);
    else if (mode == "fast")        return std::make_unique<FastMode>(data);
    else if (mode == "tournament")  return std::make_unique<TournamentMode>(data);
    else                            throw NotFoundMode(mode);
}