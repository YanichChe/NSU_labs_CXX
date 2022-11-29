#include "titForTat.h"

void TitForTat::updateStrategyData(const std::array<Move, 2> results)
{
    this->results = results;
}

Move TitForTat::algorithm()
{
    if (results[0] == D || results[1] == D)
    {
        return D;
    }
    return C;
}
