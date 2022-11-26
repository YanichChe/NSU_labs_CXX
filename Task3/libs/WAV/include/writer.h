#ifndef TASK3_WRITER_H
#define TASK3_WRITER_H

#include "wav.h"
#include <iostream>
#include <fstream>
#include <exception>

class Writer {
public:
    Writer(FILE* output);
    ~Writer();
    void write(int16_t *buffer);
private:
    WAV wav;
    FILE* output;
};

#endif //TASK3_WRITER_H
