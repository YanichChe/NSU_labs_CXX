#ifndef STRATEGY_H
#define STRATEGY_H

#include <cstdlib>
#include <vector>
#include <string>
#include <array>
#include <exception>
#include <vector>

namespace strategy{
enum Move {
    D = 1,
    C = 0
};

class Strategy {
public:
    virtual ~Strategy() = default;

    virtual Move algorithm() = 0;

    virtual void updateStrategyData(const std::array<Move, 2> results) {};
};

}
#endif
