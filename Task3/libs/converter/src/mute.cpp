#include "mute.h"

Mute::Mute(const std::vector<std::string> parameters)
{
    start = std::stoi(parameters[1]);
    end = std::stoi(parameters[2]);
}

void Mute::convert(std::vector<SampleBuffer> current_samples,
                   const std::vector<SampleBuffer> original_samples)
{
    for (int i = start; i <= end; i++)
    {
        for (int j = 0; j < SAMPLES_PER_SEC; j++)
        {
            current_samples[i][j] -= (int16_t) (current_samples[i][j] * PERCENT);
        }
    }
}
