#ifndef TASK3_SOUNDPROCESSOR_H
#define TASK3_SOUNDPROCESSOR_H

#include "converterFactory.h"
#include "reader.h"
#include "writer.h"
#include <regex>
#include <stdexcept>

namespace soundProcessor {

    class NotFileInput: public std::invalid_argument{
    public:
        NotFileInput() : std::invalid_argument("not input file"){};
    };

    class SoundProcessor {
    public:
        SoundProcessor(std::string configFile,
                       std::string outputFile,
                       std::vector<std::string> inputFiles);

        void start();

    private:
        std::string configFile;
        std::string outputFile;
        std::vector<std::string> inputFiles;

        std::vector<wav::SampleVector> inputFilesSamples;

        void fillInputSamples();

        void writeOutput(const std::vector<wav::SampleBuffer> resultSamples);
    };
}
#endif //TASK3_SOUNDPROCESSOR_H
