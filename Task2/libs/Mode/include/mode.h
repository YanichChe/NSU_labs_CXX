#ifndef MODE_H
#define MODE_H

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "strategyFactory.h"
#include "gameData.h"

using namespace matrix;
using namespace strategy;
using namespace gameData;

namespace mode {
    class Mode {
    public:
        Mode(GameData *data);

        virtual ~Mode() = default;

        virtual std::array<int, PLAYERS_NUMBER> start() = 0;

        const std::array<Move, PLAYERS_NUMBER> getVotes();

        void updateTotalSums(std::array<Move, PLAYERS_NUMBER> results);

        void updateStrategies(std::array<Move, PLAYERS_NUMBER> results);

    protected:
        std::vector<std::string> strategyNames;
        int steps;
        std::string configs;
        Matrix matrix;

        std::array<StrategyPointer, 3> strategies;

        std::array<int, PLAYERS_NUMBER> totalSums = {0, 0, 0};
    };
}
#endif