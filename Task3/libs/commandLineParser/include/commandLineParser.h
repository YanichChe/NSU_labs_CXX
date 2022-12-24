#ifndef TASK3_COMMANDLINEPARSER_H
#define TASK3_COMMANDLINEPARSER_H

#ifndef COMMAND_LINE_PARSER_H
#define COMMAND_LINE_PARSER_H

#include "boost/program_options.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace po = boost::program_options;

struct Options
{
    std::string configFile;
    std::string outputFile;
    std::vector<std::string> inputFiles;

};

bool setOptionsValue(int argc, char **argv, Options &options);

#endif

#endif //TASK3_COMMANDLINEPARSER_H
