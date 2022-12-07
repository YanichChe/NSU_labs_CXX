#include <iostream>
#include "mix.h"

using namespace mix;

WrongFileIndex ::WrongFileIndex(const int index) : std::invalid_argument(std::to_string(index) + "is bad argument"){}

Mix::Mix(const std::vector<std::string> parameters)
{
    std::string strIndexFile = parameters[1];
    this->indexFile = std::stoi(strIndexFile.erase(0, 1)) - 1;
    this->start = std::stoi(parameters[2]);
}

void Mix::convert(std::vector<wav::SampleBuffer>& current_samples,
                  const std::vector<wav::SampleVector> original_samples)
{
    if (indexFile < 0 || indexFile >= original_samples.size())      throw WrongFileIndex(indexFile);
    if (start >= current_samples.size())                            throw converter::WrongTime(start);

    for (int i = start; i < current_samples.size(); i++)
    {
        current_samples.pop_back();
    }

    for (int i = 0; i < original_samples[indexFile].size(); i++)
    {
        current_samples.push_back(original_samples[indexFile][i]);
    }
}