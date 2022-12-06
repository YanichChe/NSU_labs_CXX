#include "converterFactory.h"

ConverterPointer ConverterFactory::createConverter(const std::vector<std::string> parameters)
{
    std::string converterName = parameters[0];

    if (converterName == "mix")         return std::make_unique<Mix>(parameters);
    else if (converterName == "mute")   return std::make_unique<Mute>(parameters);
}


