#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "../libs/WAV/include/reader.h"
int main()
{
    Reader reader;
    const char *path = "C:/Users/Yana228/LABS_NSU/Task3/examples/district_four.wav";
    reader.load(path);

    return EXIT_SUCCESS;
}
