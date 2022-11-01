#include "copyMove.h"

CopyMove ::CopyMove()
{
    lastMove = C;
}

Move CopyMove::Algoritm()
{
    return lastMove;
}

