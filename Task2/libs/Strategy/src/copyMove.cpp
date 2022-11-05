#include "copyMove.h"

void CopyMove::UpdateStrategyData(std::array<Move, 2> results)
{
    for (int i = 0; i < 2; i++)
    {
        strategiesVotes[i].push_back(results[i]);
    }
}

Move CopyMove::Algoritm()
{
    return C;
}
