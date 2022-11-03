#include "matrix.h"

Matrix::Matrix(std::string fileName)
{
    std::ifstream file(fileName);
    const int row = 8, column = 3;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            file >> matrix[i][j];
}

std::array<std::array<int, 8>, 3> Matrix::GetMatrix()
{
    return matrix;
}