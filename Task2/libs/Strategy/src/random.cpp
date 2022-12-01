#include "random.h"

Random::Random()
{
    srand(time(nullptr));
}
strategy::Move Random::algorithm()
{
    return static_cast<strategy::Move>(rand() % 2);
}
