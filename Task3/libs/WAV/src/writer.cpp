#include "writer.h"

Writer::Writer(const std::string path)
{
    outputFile.open(path, std::ios_base::binary);
    outputFile.seekp(TOTAL_HEADER_SIZE, std::fstream::cur);
}

void Writer::writeHeader()
{
    outputFile.seekp(0, std::ios::beg);

    Header RIFFHeader{RIFF_CHUNK_ID, (uint32_t)outputFile.tellp() - BYTE_SIZE};
    Header FMTHeader{FMT_CHUNK_ID, FMT_CHUNK_SIZE};
    Header dataHeader{DATA_CHUNK_ID, (uint32_t)outputFile.tellp() - TOTAL_HEADER_SIZE};

    wav.RIFFHeader = RIFFHeader;
    wav.WAVEFormat = WAVE_FORMAT;
    wav.FMTHeader = FMTHeader;
    wav.audioFormat = AUDIO_FORMAT;
    wav.numberChannels = NUMBER_CHANNELS;
    wav.samplesPerSec = SAMPLES_PER_SEC;
    wav.bytesPerSec = BYTES_PER_SEC;
    wav.blockAlign = BLOCK_ALIGN;
    wav.bitsPerSample = BITS_PER_SAMPLE;
    wav.dataHeader = dataHeader;

    outputFile.write((const char *)&wav, sizeof(WAV));

}

void Writer::writeSample(std::array<int16_t, SAMPLES_PER_SEC> *buffer)
{
    outputFile.write((char*)buffer, sizeof(buffer));
}