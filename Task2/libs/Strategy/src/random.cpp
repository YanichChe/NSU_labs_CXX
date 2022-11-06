#include "random.h"

Move Random::Algoritm()
{
    Move move = (Move)GetRandomNumber(0, 1);
    return move;
}

int GetRandomNumber(int min, int max)
{

    srand(time(NULL));
    int num = min + rand() % (max - min + 1);
    return num;
}