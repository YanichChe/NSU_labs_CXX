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
    void writeSample(int16_t *buffer);
private:
    WAV wav;
    std::ofstream outputFile;
    void writeHeader();
    std::string path;
};

#endif //TASK3_WRITER_H
