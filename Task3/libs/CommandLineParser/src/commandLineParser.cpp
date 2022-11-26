#include "commandLineParser.h"

bool SetOptionsValue(int argc, char **argv, Options &options)
{
    po::options_description desc("All options");
    desc.add_options()("help", "Show options description")
            ("configs", po::value<std::string>(&options.configFile), "Name of config file")
            ;

    po::variables_map vm;

    try
    {
        po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
        po::notify(vm);
    }

    catch (po::error &e)
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