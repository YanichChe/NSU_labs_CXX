#ifndef MODE_H
#define MODE_H

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "strategyFactory.h"
#include "gameData.h"

namespace mode {
    class Mode {
    public:
        Mode(gameData::GameData *data);

        virtual ~Mode() = default;

        virtual std::array<int, matrix::PLAYERS_NUMBER> start() = 0;

        const std::array<strategy::Move, matrix::PLAYERS_NUMBER> getVotes();

        void updateTotalSums(std::array<strategy::Move, matrix::PLAYERS_NUMBER> results);

        void updateStrategies(std::array<strategy::Move, matrix::PLAYERS_NUMBER> results);

    protected:
        std::vector<std::string> strategyNames;
        int steps;
        std::string configs;
        matrix::Matrix matrix;

        std::array<strategyFactory::StrategyPointer, 3> strategies;

        std::array<int, matrix::PLAYERS_NUMBER> totalSums = {0, 0, 0};
    };
}
#endif