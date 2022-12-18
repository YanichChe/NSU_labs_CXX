#include "soundProcessor.h"

using namespace soundProcessor;

SoundProcessor::SoundProcessor(std::string configFile, std::string outputFile, std::vector<std::string> inputFiles)
{
    std::filesystem::path cwd = std::filesystem::current_path();
    std::string path = cwd.string() + "\\..\\" + "examples\\";
    std::cout << path << std::endl;

    this->configFile = path + configFile;
    this->outputFile = path + outputFile;

    for (int i = 0; i < inputFiles.size(); i++)
    {
        this->inputFiles.push_back(path + inputFiles[i]);
    }

    if (inputFiles.size() == 0) throw NotFileInput();
    fillInputSamples();
}

void SoundProcessor ::start()
{
    try {
        wav::SampleVector resultSamples = inputFilesSamples[0];

        converterFactory::ConverterFactory factory;

        std::ifstream inputFile;
        inputFile.open(configFile);

        std::string currentLine;
        while (std::getline(inputFile, currentLine)) {
            std::regex re(" ");
            std::sregex_token_iterator first{currentLine.begin(), currentLine.end(), re, -1}, last;
            std::vector<std::string> parameters{first, last};

            converterFactory::ConverterPointer currentConverter = factory.createConverter(parameters);
            currentConverter->convert(resultSamples, inputFilesSamples);
        }

        writeOutput(resultSamples);
    }
    catch(const std::ifstream::failure& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void SoundProcessor::writeOutput(const std::vector<wav::SampleBuffer> resultSamples)
{
    writer::Writer writer(outputFile);
    for (int i = 0; i < resultSamples.size(); i++)
    {
        wav::SampleBuffer buffer = resultSamples[i];
        writer.writeSample(&buffer);
    }
    writer.writeHeader();
}

void SoundProcessor::fillInputSamples()
{
    for (int i = 0; i < inputFiles.size(); i++)
    {
        reader::Reader reader;
        reader.load(inputFiles[i]);

        wav::SampleVector currentSamples;

        std::ifstream file(configFile);
        std::istream_iterator<std::string> eof;
        std::string number = "$" + std::to_string(i + 1);
        bool found = find(std::istream_iterator<std::string>(file), eof, number) != eof;

        if (found || i == 0)
        {
            while (true)
            {
                wav::SampleBuffer buffer;
                if (!reader.readSample(&buffer)) break;
                currentSamples.push_back(buffer);
            }
        }
        inputFilesSamples.push_back(currentSamples);
    }
}