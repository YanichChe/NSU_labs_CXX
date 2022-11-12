#include <iostream>
#include "gameData.h"
#include "commandLineParser.h"
#include "game.h"

int main(int argc, char **argv)
{
    Options options;
    if (!SetOptionsValue(argc, argv, options))
    {
        return EXIT_SUCCESS;
    }

    GameData data(options.strategyNames,
                  options.steps,
                  options.configs,
                  options.matrixFile);

    Game game;
    game.StartGame(&data, options.mode);

    return 0;
}
