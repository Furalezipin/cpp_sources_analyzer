#include "commandlineparser.h"

#include <iostream>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options.hpp>

using namespace boost::program_options;

CommandLineParser::CommandLineParser() {

}

const std::string& CommandLineParser::getSourceFolder() {
    return m_sourceFolder;
}

const std::list<std::string>& CommandLineParser::getListIncudeDirs() {
    return std::list(m_listIncludeDirs.begin(), m_listIncludeDirs.end());
}

ParseResult CommandLineParser::parseArguments(int argc, char **argv) {
    options_description desc("Available options");
    desc.add_options()
            ("help", "Print usage")
            ("input,i", value<std::vector<std::string>>(&m_listIncludeDirs)->multitoken(), "Include directories")
            ("sources_directory", value<std::string>(&m_sourceFolder), "Directory with source files");

    positional_options_description positionals;
    positionals.add("sources_directory", 1);

    variables_map vm;
    try {
        store(command_line_parser(argc, argv)
            .options(desc)
            .positional(positionals)
            .run(), vm);
        notify(vm);
    } catch (error& e) {
        std::cout << "ERROR: " << e.what() << "\n";
        std::cout << desc << "\n";
        return ParseResult::Result_Error;
    }

    if (vm.count ("help")) {
        std::cerr << desc << "\n";
    }

    return ParseResult::Result_Ok;
}
