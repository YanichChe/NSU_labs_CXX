#include "modeFactory.h"

ModePtr ModeFactory::Create(std::string & mode, GameData* data)
{
    if (mode == "detailed") return std::make_unique<DetailedMode>(data);
    else if (mode == "fast") return std::make_unique<FastMode>(data);
}