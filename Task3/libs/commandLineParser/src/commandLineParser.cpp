#include "commandLineParser.h"

bool setOptionsValue(int argc, char **argv, Options &options)
{
    po::options_description desc("All options");
    desc.add_options()("help, h", "Show options description")
            ("configs, c", po::value<std::string>(&options.configFile), "Name of config file")
            ("output_file, o", po::value<std::string>(&options.outputFile), "Name of output file")
            ("input_files, i", po::value<std::vector<std::string>>(&options.inputFiles)->multitoken(), "Names of input files");

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