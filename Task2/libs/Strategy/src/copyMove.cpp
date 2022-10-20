#include "copyMove.h"

CopyMove ::CopyMove(GameData *data)
{
    Matrix* matrix = data->GetMatrix();
    this->moves = matrix->GetMoves();
}

Move CopyMove::Algoritm()
{
    return C;
}

Strategy *CreateStrategy(GameData *data)
{
    return new CopyMove(data);
}