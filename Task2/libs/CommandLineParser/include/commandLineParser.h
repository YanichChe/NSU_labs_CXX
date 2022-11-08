#ifndef COMMAND_LINE_PARSER_H
#define COMMAND_LINE_PARSER_H

#include "boost/program_options.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace po = boost::program_options;

struct Options
{
    std::vector<std::string> strategyNames;
    std::string mode;
    int steps;
    std::string configs;
    std::string matrixFile;
};

bool SetOptionsValue(int argc, char **argv, Options &options);

#endif