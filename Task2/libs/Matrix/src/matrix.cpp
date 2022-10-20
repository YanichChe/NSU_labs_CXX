#include "matrix.h"

std::vector<std::vector<Move>> Matrix::GetMoves()
{
    return this->moves;
}

void Matrix::AddMove(int id, Move move)
{
    this->moves[id].push_back(move);
}

char GetMove(Move move)
{
    if (move == C)
        return 'C';
    return 'D';
}

std::ostream &operator<<(std::ostream &out, const Matrix &i)
{
    Matrix temp = i;
    std::vector<std::vector<Move>> matrix = temp.GetMoves();

    out << "1 2 3";

    for (int i = 0; i < matrix[0].size(); i++)
    {
        out << matrix[0][i] << " "<< matrix[1][i] << " " << matrix[2][i];
    }

    return out;
}