#include <stdlib.h>
#include "commandLineParser.h"

int main(int argc, char ** argv)
{
    Options opts;
    if (!SetOptionsValue(argc, argv, opts)) return EXIT_SUCCESS;

    return EXIT_SUCCESS;
}