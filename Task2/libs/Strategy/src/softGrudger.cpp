#include "softGrudger.h"

void SoftGrudger::updateStrategyData(const std::array<strategy::Move, 2> results)
{
    this->results = results;
}

strategy::Move SoftGrudger::algorithm()
{
    if (results[0] == strategy::D || results[1] == strategy::D)
    {
        indexPunishment = 0;
    }

    if (indexPunishment == MAX_PUNISHMENT_COUNT)
    {
        indexPunishment = -1;
        choice = strategy::C;
    }

    else if (indexPunishment >= 0)
    {
        choice = punishment[indexPunishment++];
    }

    return choice;
}