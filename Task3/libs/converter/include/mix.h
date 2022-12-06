#ifndef TASK3_MIX_H
#define TASK3_MIX_H

#include "converter.h"

class Mix : public Converter
{
public:
    Mix(const std::vector<std::string> parameters);
    void convert(std::vector<SampleBuffer> current_samples,
                 const std::vector<SampleBuffer> original_samples) override;
private:
    int start = 0;
};


#endif //TASK3_MIX_H
