#ifndef MATRIX_H
#define MATRIX_H

#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>

enum Move
{
    D,
    C
};

class Matrix
{
public:
    std::vector<std::vector<Move>> GetMoves();
    void AddMove(int id, Move move);

private:
    std::vector<std::vector<Move>> moves;
};

std::ostream &operator<<(std::ostream &out, const Matrix &i);

#endif