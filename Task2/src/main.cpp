#include <iostream>
#include "gameData.h"
#include "commandLineParser.h"
#include "game.h"

int main(int argc, char **argv)
{
    Options options;
    if (!setOptionsValue(argc, argv, options))
    {
        return EXIT_SUCCESS;
    }

    gameData::GameData data(options.strategyNames,
                  options.steps,
                  options.configs,
                  options.matrixFile);

    Game game;
    game.startGame(&data, options.mode);

    return 0;
}
