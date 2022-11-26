#include "writer.h"

Writer::Writer(FILE* output)
{
    fwrite(&wav, 1, sizeof(wav), output);
    this->output = output;
}

Writer::~Writer()
{
    fclose(output);
}

void Writer::write(int16_t *buffer)
{
    fwrite(&buffer, 1, wav.dataChunkSize, output);
}