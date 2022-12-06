#ifndef TASK3_SOUNDPROCESSOR_H
#define TASK3_SOUNDPROCESSOR_H

#include "converterFactory.h"
#include "reader.h"
#include "writer.h"
#include "regex"

class SoundProcessor
{
public:
    SoundProcessor(std::string configFile,
                   std::string outputFile,
                   std::vector<std::string> inputFiles);
    void Start();

private:
    std::string configFile;
    std::string outputFile;
    std::vector<std::string> inputFiles;

    std::vector<std::vector<SampleBuffer>> inputFilesSamples;
    void fillInputSamples();
    void writeOutput(const std::vector<SampleBuffer> resultSamples);
};


#endif //TASK3_SOUNDPROCESSOR_H
