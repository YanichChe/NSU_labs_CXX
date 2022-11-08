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

    GameData gameData(options.strategyNames,
                      options.steps,
                      options.configs,
                      options.matrixFile);
    Game game;
    game.StartGame(&gameData, options.mode);

    return 0;
}
