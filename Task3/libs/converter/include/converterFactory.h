#ifndef TASK3_CONVERTERFACTORY_H
#define TASK3_CONVERTERFACTORY_H

#include <cstdlib>
#include <memory>
#include <string>
#include "mute.h"
#include "mix.h"

using ConverterPointer = std::unique_ptr<Converter>;
class ConverterFactory
{
public:
    ConverterPointer createConverter(const std::vector<std::string> parameters);
};

#endif //TASK3_CONVERTERFACTORY_H
