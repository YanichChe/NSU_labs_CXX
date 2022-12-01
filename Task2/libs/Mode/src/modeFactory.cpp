#include "modeFactory.h"

using namespace modeFactory;

NotFoundMode ::NotFoundMode(const std::string &mode) :
                            std::invalid_argument(mode + " not found mode") {}

ModePointer ModeFactory ::create(const std::string mode, gameData::GameData *data)
{
    if (mode == DETAILED)         return std::make_unique<DetailedMode>(data);
    else if (mode == FAST)        return std::make_unique<FastMode>(data);
    else if (mode == TOURNAMENT)  return std::make_unique<TournamentMode>(data);
    else                            throw NotFoundMode(mode);
}