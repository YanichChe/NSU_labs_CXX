#ifndef TASK2_PAVLOV_H
#define TASK2_PAVLOV_H

#include "strategyFactory.h"
#include <boost/property_tree/json_parser.hpp>
#include <memory>

const int BASE_STEPS = 6;

enum STRATEGY_NAME
{
    TIT_FOR_TAT,
    ALWAYS_DEFECT,
    RANDOM
};

namespace pt = boost::property_tree;
class Pavlov : public Strategy
{
public:
    Pavlov(std::string configs);
    Move Algoritm() override;
    void UpdateStrategyData(std::array<Move, 2> results) override;

private:
    std::array<Move, 2> results = {C, C};
    std::string configs;
    std::unique_ptr<Strategy> currentStrategy;

    int countDefections1 = 0;
    int countDefections2 = 0;
    int currentSteps = 0;

    pt::ptree configTree;

    STRATEGY_NAME GetAnswerStrategy(int countDefections);
};

#endif // TASK2_PAVLOV_H
