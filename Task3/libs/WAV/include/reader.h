#ifndef LAB1_READER_H
#define LAB1_READER_H

#include "wav.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <exception>

// INPUT VALUES ERRORS  --------------------------------------------------------------

class WrongRIFFChunkId : public std::invalid_argument
{
public:
    explicit WrongRIFFChunkId(const uint32_t RIFFChunkId);
};
class WrongWAVEFormat : public std::invalid_argument
{
public:
    explicit WrongWAVEFormat(const uint32_t wrongWAVEFormat);
};
class WrongFMTChunkId : public std::invalid_argument
{
public:
    explicit WrongFMTChunkId(const uint32_t FMTChunkId);
};
class WrongAudioFormat : public std::invalid_argument
{
public:
    explicit WrongAudioFormat(const uint16_t audioFormat);
};
class WrongNumberChannels : public std::invalid_argument
{
public:
    explicit WrongNumberChannels(const uint16_t numberChannels);
};
class WrongSamplesPerSec : public std::invalid_argument
{
public:
    explicit WrongSamplesPerSec(const uint32_t samplesPerSec);
};

class WrongBlockAlign : public std::invalid_argument
{
public:
    explicit WrongBlockAlign(const uint16_t blockAlign);
};
class WrongBitesPerSample : public std::invalid_argument
{
public:
    explicit WrongBitesPerSample(const uint16_t bitesPerSample);
};

class WrongBytesPerSec : public std::invalid_argument
{
public:
    explicit WrongBytesPerSec(const uint32_t bytesPerSec);
};

class WrongDataChunkId : public std::invalid_argument
{
public:
    explicit WrongDataChunkId(const uint32_t dataChunkId);
};

//----------------------------------------------------------------------------------

class Reader
{
public:
    Reader(){};
    ~Reader(){};
    void load(const std::string path);
    bool readSample(int16_t *buffer);

private:
    WAV wav;
    std::ifstream inputFile;
    bool checkInput();
};

#endif // LAB1_READER_H
