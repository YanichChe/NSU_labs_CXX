#ifndef TASK3_CONVERTER_H
#define TASK3_CONVERTER_H

#include <cstdlib>
#include <vector>
#include <array>
#include "wav.h"

using SampleBuffer = std::array<int16_t, SAMPLES_PER_SEC>;
class Converter
{
public:
    virtual ~Converter() = default;
    virtual void convert(std::vector<SampleBuffer> current_samples,
                         const std::vector<SampleBuffer> original_samples) = 0;
};
#endif //TASK3_CONVERTER_H
