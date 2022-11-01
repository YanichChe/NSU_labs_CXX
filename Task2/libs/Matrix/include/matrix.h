#ifndef MATRIX_H
#define MATRIX_H

#include <cstdlib>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>
class Matrix
{
public:
    Matrix(std::string fileName);
    std::array<std::array<int, 8>, 3> GetMatrix();

private:
    std::array<std::array<int, 8>, 3> matrix;
};

#endif