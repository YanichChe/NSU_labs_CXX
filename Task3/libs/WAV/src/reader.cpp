#include "reader.h"

// INPUT VALUES ERRORS  --------------------------------------------------------------
WrongRIFFChunkId ::WrongRIFFChunkId(const uint32_t RIFFChunkId) : 
std::invalid_argument(std::to_string(RIFFChunkId) + " is not RIFF") {}

WrongWAVEFormat ::WrongWAVEFormat(const uint32_t wrongWAVEFormat) : 
std::invalid_argument(std::to_string(wrongWAVEFormat) + "is not WAVE") {}

WrongFMTChunkId ::WrongFMTChunkId(const uint32_t FMTChunkId) : 
std::invalid_argument(std::to_string(FMTChunkId) + " is not FMT") {}

WrongAudioFormat ::WrongAudioFormat(const uint16_t audioFormat) : 
std::invalid_argument(std::to_string(audioFormat) + " is not PML") {}

WrongNumberChannels ::WrongNumberChannels(const uint16_t numberChannels) : 
std::invalid_argument(std::to_string(numberChannels) + " is not mono") {}

WrongSamplesPerSec ::WrongSamplesPerSec(const uint32_t samplesPerSec) : 
std::invalid_argument(std::to_string(samplesPerSec) + " is not 44100") {}

WrongBytesPerSec::WrongBytesPerSec(const uint32_t bytesPerSec) : 
std::invalid_argument(std::to_string(bytesPerSec) + " is wrong bytes per sec value") {}

WrongBitesPerSample::WrongBitesPerSample(const uint16_t bitesPerSample) : 
std::invalid_argument(std::to_string(bitesPerSample) + " is wrong bytes per sec value") {}

WrongBlockAlign::WrongBlockAlign(const uint16_t blockAlign) : 
std::invalid_argument(std::to_string(blockAlign) + " is wrong block align value") {}

WrongDataChunkId ::WrongDataChunkId(const uint32_t dataChunkId) : 
std::invalid_argument(std::to_string(dataChunkId) + " is not data") {}

//----------------------------------------------------------------------------------
void Reader::Load(const char *path)
{
    wavFile = fopen(path, "r");
    fread(&wav, 1, sizeof(WAV), wavFile);
    CheckInput();
}

void Reader::ReadSample(int16_t *buffer)
{
    static const uint16_t bufferSize = wav.samplesPerSec;
    fread(buffer, sizeof(int16_t), bufferSize / (sizeof buffer[0]), wavFile);
}

bool Reader::CheckInput()
{
    if (wav.RIFFChunkId != RIFF_CHUNK_ID)               throw WrongRIFFChunkId(wav.RIFFChunkId);
    else if (wav.WAVEFormat != WAVE_FORMAT)             throw WrongWAVEFormat(wav.WAVEFormat);
    else if (wav.FMTChunkId != FMT_CHUNK_ID)            throw WrongFMTChunkId(wav.FMTChunkId);
    else if (wav.audioFormat != AUDIO_FORMAT)           throw WrongAudioFormat(wav.audioFormat);
    else if (wav.numberChannels != NUMBER_CHANNELS)     throw WrongNumberChannels(wav.numberChannels);
    else if (wav.samplesPerSec != SAMPLES_PER_SEC)      throw WrongSamplesPerSec(wav.samplesPerSec);
    else if (wav.bytesPerSec != BYTES_PER_SEC)          throw WrongBytesPerSec(wav.bytesPerSec);
    else if (wav.bitsPerSample != BITS_PER_SAMPLE)      throw WrongBitesPerSample(wav.bitsPerSample);
    else if (wav.blockAlign != BLOCK_ALIGN)             throw WrongBlockAlign(wav.blockAlign);
    else if (wav.dataChunkId != DATA_CHUNK_ID)          throw WrongDataChunkId(wav.dataChunkId);

    return true;
}