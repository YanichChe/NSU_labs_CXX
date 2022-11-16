#include "pavlov.h"

Pavlov ::Pavlov(std::string configs)
{
    this->configs = configs;
    pt::read_json(configs + "pavlov.json", configTree);

    StrategyFactory strategyFactory;
    this->currentStrategy = strategyFactory.createStrategy(configTree.get<std::string>("Base"), configs);
}

void Pavlov::UpdateStrategyData(std::array<Move, 2> results)
{
    this->results = results;

    if (currentSteps < BASE_STEPS)
    {
        countDefections1 += results[0];
        countDefections2 += results[1];
    }

    else
    {
        std::string newStrategyName;
        STRATEGY_NAME newStrategy = std::max(GetAnswerStrategy(countDefections1),
                                             GetAnswerStrategy(countDefections2));

        if (newStrategy == TIT_FOR_TAT)         newStrategyName = "titForTat";
        else if (newStrategy == ALWAYS_DEFECT)  newStrategyName = "alwaysDefect";
        else                                    newStrategyName = "random";

        StrategyFactory strategyFactory;
        currentStrategy = strategyFactory.createStrategy(configTree.get<std::string>(newStrategyName), configs);
    }
}

STRATEGY_NAME Pavlov::GetAnswerStrategy(int countDefections)
{
    if (countDefections == 0)       return TIT_FOR_TAT;
    else if (countDefections > 3)   return ALWAYS_DEFECT;
    else                            return RANDOM;
}

Move Pavlov::Algoritm()
{
    currentSteps++;
    return currentStrategy->Algoritm();
}
