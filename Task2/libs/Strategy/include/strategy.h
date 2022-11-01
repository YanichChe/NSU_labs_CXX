#ifndef STRATEGY_H
#define STRATEGY_H

#include <stdlib.h>
#include <vector>
#include <string>

enum Move
{
    D = 0,
    C = 1
};

class Strategy
{
public:
    virtual ~Strategy() = default; 
    virtual Move Algoritm() = 0;
};


#endif
