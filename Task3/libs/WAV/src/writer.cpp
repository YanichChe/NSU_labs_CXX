#include "writer.h"

Writer::Writer(const std::string path)
{
    this->path = path;
    outputFile.open(path, std::ios_base::binary);
}

void Writer::writeHeader()
{
    outputFile.seekp(0, std::ios::beg);

    Header RIFFHeader{RIFF_CHUNK_ID, TOTAL_HEADER_SIZE - BYTE_SIZE + (uint32_t)outputFile.tellp()};
    Header FMTHeader{FMT_CHUNK_ID, FMT_CHUNK_SIZE};
    Header dataHeader{DATA_CHUNK_ID, (uint32_t)outputFile.tellp()};

    wav.RIFFHeader = RIFFHeader;
    wav.WAVEFormat = WAVE_FORMAT;
    wav.FMTHeader = FMTHeader;
    wav.audioFormat = AUDIO_FORMAT;
    wav.numberChannels = NUMBER_CHANNELS;
    wav.samplesPerSec = SAMPLES_PER_SEC;
    wav.bytesPerSec = BYTES_PER_SEC;
    wav.blockAlign = BLOCK_ALIGN;
    wav.bitsPerSample = BITS_PER_SAMPLE;

    outputFile.write((const char *)&wav, sizeof(WAV));

}

void Writer::writeSample(int16_t *buffer)
{
    static const uint16_t bufferSize = wav.samplesPerSec;
    outputFile.write((char*)buffer, bufferSize / (sizeof buffer[0]));
}