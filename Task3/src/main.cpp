#include <cstdlib>
#include "commandLineParser.h"
#include "soundProcessor.h"

int main(int argc, char **argv)
{
    Options options;
    if (!setOptionsValue(argc, argv, options))
    {
        return EXIT_SUCCESS;
    }

    try {
        soundProcessor::SoundProcessor soundProcessor(options.configFile, options.outputFile, options.inputFiles);
        soundProcessor.start();
    }
    catch(const soundProcessor::NotFileInput& e)
    {
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
