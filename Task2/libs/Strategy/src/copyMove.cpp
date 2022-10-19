#include "copyMove.h"

CopyMove ::CopyMove(GameData *data)
{
    this->moves = data->GetMoves();
}

Move CopyMove::Algoritm()
{
    return C;
}

Strategy *CreateStrategy(GameData *data)
{
    return new CopyMove(data);
}