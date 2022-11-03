//
// Created by Yana228 on 03.11.2022.
//

#ifndef TASK2_MATRIX_H
#define TASK2_MATRIX_H

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

#endif //TASK2_MATRIX_H
