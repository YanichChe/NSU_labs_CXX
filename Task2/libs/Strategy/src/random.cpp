#include "random.h"

Random::Random()
{
    srand(time(nullptr));
}
Move Random::algorithm()
{
    return static_cast<Move>(rand() % 2);
}
