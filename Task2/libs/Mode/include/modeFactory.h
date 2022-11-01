#ifndef MODE_FACTORY_H
#define MODE_FACTORY_H

#include <memory>
#include <string>

#include "mode.h"

using ModePtr = std::unique_ptr<Mode>;

class ModeCreator
{
public:
    ModePtr Create(std::vector<std::string> & strategy_names, std::string & mode, 
                   int steps, std::string & configs, Matrix matrix);
};

#endif