#include "matrix.h"

using namespace matrix;

NotFoundFileException ::NotFoundFileException(const std::string &matrix_file) : std::invalid_argument(matrix_file + " not found file") {}

Matrix::Matrix(const std::string fileName)
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

const std::array<std::array<int, PLAYERS_NUMBER>, 8>* Matrix::getMatrix()
{
    return &matrix;
}

const std::array<int, PLAYERS_NUMBER>* Matrix::getRow(std::array<strategy::Move, PLAYERS_NUMBER> votes)
{
    int row = 0;

    for (int i = 0; i < PLAYERS_NUMBER; i++)
    {
        row = (row << 1) + votes[i];
    }

    return &matrix[row];
}