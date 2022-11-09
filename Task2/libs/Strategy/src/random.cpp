#include "random.h"

Random::Random()
{
    srand(time(nullptr));
}
Move Random::Algoritm()
{
    return static_cast<Move>(rand() % 2);
}

