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
    if (strategiesVotes.empty())
    {
        return D;
    }

    else
    {
        int index = strategiesVotes.size() - 1;
        if (strategiesVotes[0][index] == strategiesVotes[1][index])
        {
            return D;
        }

        else
        {

        }
    }

}
