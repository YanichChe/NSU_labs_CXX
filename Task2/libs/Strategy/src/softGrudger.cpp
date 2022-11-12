#include "softGrudger.h"

void SoftGrudger::UpdateStrategyData(std::array<Move, 2> results)
{
    this->results = results;
}

Move SoftGrudger::Algoritm()
{
    if (results[0] == D || results[1] == D)
    {
        indexPunishment = 0;
    }

    if (indexPunishment == MAX_PUNISHMENT_COUNT)
    {
        indexPunishment = -1;
        choice = C;
    }

    else if (indexPunishment >= 0)
    {
        choice = punishment[indexPunishment++];
    }

    return choice;
}