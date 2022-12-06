#ifndef TASK3_WRITER_H
#define TASK3_WRITER_H

#include "wav.h"
#include <iostream>
#include <fstream>
#include <exception>

class Writer {
public:
    Writer(const std::string path);
    ~Writer(){};
    void writeSample(std::array<int16_t, SAMPLES_PER_SEC> *buffer);
    void writeHeader();
private:
    WAV wav;
    std::ofstream outputFile;
};

#endif //TASK3_WRITER_H
