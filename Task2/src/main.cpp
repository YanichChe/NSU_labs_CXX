#include <cstdlib>
#include "commandLineParser.h"

int main(int argc, char ** argv)
{
    Options gameOptions;
    if (!SetOptionsValue(argc, argv,gameOptions))
    {
        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}