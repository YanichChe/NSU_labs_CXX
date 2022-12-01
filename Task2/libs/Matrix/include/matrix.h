#ifndef TASK2_MATRIX_H
#define TASK2_MATRIX_H

#include <cstdlib>
#include <exception>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>
#include "strategy.h"

namespace matrix {
    const int PLAYERS_NUMBER = 3;

    class NotFoundFileException : public std::invalid_argument {
    public:
        explicit NotFoundFileException(const std::string &fileName);
    };

    class Matrix {
    public:
        Matrix() {};

        Matrix(const std::string fileName);

        const std::array<std::array<int, PLAYERS_NUMBER>, 8>* getMatrix();

        const std::array<int, PLAYERS_NUMBER>* getRow(std::array<strategy::Move, PLAYERS_NUMBER> votes);

    private:
        std::array<std::array<int, PLAYERS_NUMBER>, 8> matrix;
    };
}
#endif // TASK2_MATRIX_H
