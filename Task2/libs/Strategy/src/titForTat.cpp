#include "titForTat.h"

void TitForTat::updateStrategyData(const std::array<strategy::Move, 2> results)
{
    this->results = results;
}

strategy::Move TitForTat::algorithm()
{
    if (results[0] == strategy::D || results[1] == strategy::D)
    {
        return strategy::D;
    }
    return strategy::C;
}
