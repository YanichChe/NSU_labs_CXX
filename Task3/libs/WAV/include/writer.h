#ifndef TASK3_WRITER_H
#define TASK3_WRITER_H

#include "wav.h"
#include <iostream>
#include <fstream>
#include <exception>

namespace writer {
    class Writer {
    public:
        Writer(const std::string path);

        ~Writer() {};

        void writeSample(const wav::SampleBuffer *buffer);

        void writeHeader();

    private:
        wav::WAV wav;
        std::ofstream outputFile;
    };
}
#endif //TASK3_WRITER_H
