#include "soundProcessor.h"

SoundProcessor::SoundProcessor(std::string configFile, std::string outputFile, std::vector<std::string> inputFiles)
{
    this->configFile = configFile;
    this->outputFile = outputFile;
    this->inputFiles = inputFiles;

    fillInputSamples();
}

void SoundProcessor ::Start()
{
    std::vector<SampleBuffer> resultSamples;

    ConverterFactory factory;

    std::ifstream inputFile;
    inputFile.open(configFile);

    std::string currentLine;
    while(std::getline(inputFile, currentLine))
    {
        std::regex re(" ");
        std::sregex_token_iterator first{currentLine.begin(), currentLine.end(), re, -1}, last;
        std::vector<std::string> parameters{first, last};

        ConverterPointer currentConverter = factory.createConverter(parameters);


    }

    writeOutput(resultSamples);
}

void SoundProcessor::writeOutput(const std::vector<SampleBuffer> resultSamples)
{
    Writer writer(outputFile);
    for (int i = 0; i < resultSamples.size(); i++)
    {
        SampleBuffer buffer = resultSamples[i];
        writer.writeSample(&buffer);
    }

    writer.writeHeader();
}

void SoundProcessor::fillInputSamples()
{
    for (int i = 0; i < inputFiles.size(); i++)
    {
        Reader reader;
        reader.load(inputFiles[i]);

        std::vector<SampleBuffer> currentSamples;
        while (true)
        {
            SampleBuffer buffer;
            if (!reader.readSample(&buffer)) break;
            currentSamples.push_back(buffer);
        }

        inputFilesSamples.push_back(currentSamples);
    }
}