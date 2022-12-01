#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "../libs/WAV/include/reader.h"
#include "../libs/WAV/include/writer.h"

int main()
{
    Reader reader;
    const std::string path = "C:/Users/Yana228/LABS_NSU/Task3/examples/district_four.wav";
    reader.load(path);

    Writer writer();





    return EXIT_SUCCESS;
}
