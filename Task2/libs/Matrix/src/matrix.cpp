#include "matrix.h"

NotFoundFileException ::NotFoundFileException(const std::string &matrix_file) : std::invalid_argument(matrix_file + " not found file") {}

Matrix::Matrix(std::string fileName)
{
    std::ifstream file(fileName);
    const int row = 8, column = PLAYERS_NUMBER;

    if (file.is_open())
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                file >> matrix[i][j];
            }
        }
    }

    else
    {
        throw NotFoundFileException(fileName);
    }
}

std::array<std::array<int, PLAYERS_NUMBER>, 8> Matrix::GetMatrix()
{
    return matrix;
}

std::array<int, PLAYERS_NUMBER> Matrix::GetRow(std::array<Move, 3> votes)
{
    int row = 0;

    for (int i = 0; i < PLAYERS_NUMBER; i++)
    {
        row = (row << 1) + votes[i];
    }

    return  matrix[row];
}