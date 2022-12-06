#include "mix.h"

Mix::Mix(const std::vector<std::string> parameters)
{
    start = std::stoi(parameters[1]);
}

void Mix::convert(std::vector<SampleBuffer> current_samples,
                  const std::vector<SampleBuffer> original_samples)
{
    for (int i = start; i < current_samples.size(); i++)
    {
        current_samples.pop_back();
    }

    for (int i = 0; i < original_samples.size(); i++)
    {
        current_samples.push_back(original_samples[i]);
    }
}