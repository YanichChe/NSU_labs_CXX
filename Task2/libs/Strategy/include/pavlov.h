#ifndef TASK2_PAVLOV_H
#define TASK2_PAVLOV_H

#include "strategyFactory.h"

enum StrategyName
{
    TIT_FOR_TAT,
    ALWAYS_DEFECT,
    RANDOM
};

class Pavlov : Strategy
{
public:
    Pavlov(std::string configs);
    Move Algoritm() override;
    void UpdateStrategyData(std::array<Move, 2> results) override;

private:
    std::array<Move, 2> results = {C, C};
    StrategyPointer strategy;

    int countD1 = 0;
    int countD2 = 0;

    int currentSteps = 0;

    StrategyName ChooseStrategy(int coutD1, int count2);
};

#endif // TASK2_PAVLOV_H
