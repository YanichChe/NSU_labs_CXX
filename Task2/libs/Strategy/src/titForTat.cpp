#include "titForTat.h"

void TitForTat::UpdateStrategyData(std::array<Move, 2> results)
{
    this->results = results;
}

Move TitForTat::Algoritm()
{
    if (results[0] == D || results[1] == D)
    {
        return D;
    }
    return C;
}
