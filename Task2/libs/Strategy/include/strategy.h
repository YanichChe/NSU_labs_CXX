#include <stdlib.h>
#include <vector>

enum Move { D, C };

class Strategy
{
public:
    virtual int Algoritm(std::vector <int> mine, std::vector <int> opponentA, std::vector <int> opponentB) = 0;
};

