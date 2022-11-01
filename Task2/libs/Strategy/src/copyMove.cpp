#include "copyMove.h"

CopyMove ::CopyMove()
{

}

Move CopyMove::Algoritm()
{
    return C;
}

Strategy *CreateStrategy()
{
    return new CopyMove();
}