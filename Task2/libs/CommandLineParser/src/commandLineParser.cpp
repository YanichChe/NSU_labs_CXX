#include "commandLineParser.h"

bool SetOptionsValue(int argc, char ** argv, Options & options)
{
    po::options_description desc("All options");
    desc.add_options()
            ("help", "Show options description")
            ("names", po::value<std::vector<std::string>>(&options.strategyNames)->multitoken(), "Strategy names")
            ("mode", po::value<std::string>(&options.mode), "Game mode")
            ("steps", po::value<int>(&options.steps), "Number steps")
            ("configs", po::value<std::string>(&options.configs), "Directory with strategy configuration files")
            ("matrix", po::value<std::string>(&options.matrixFile), "Matrix file");

    po::variables_map vm;

    try
    {
        po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
        po::notify(vm);
    }

    catch (po::error& e)
    {
        std::cout << e.what() << std::endl;
        std::cout << desc << std::endl;
        return false;
    }

    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return false;
    }

    return true;
}