#ifndef TASK3_MUTE_H
#define TASK3_MUTE_H

#include "converter.h"

const float PERCENT   = 0.6f;

class Mute : public Converter
{
public:
    Mute(const std::vector<std::string> parameters);
    void convert(std::vector<SampleBuffer> current_samples,
                 const std::vector<SampleBuffer> original_samples) override;
private:
    int start = 0;
    int end = 0;
};


#endif //TASK3_MUTE_H
