#include "commandlineparser.h"

#include <iostream>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options.hpp>

using namespace boost::program_options;

CommandLineParser::CommandLineParser() {

}

ParseResult CommandLineParser::parseArguments(int argc, char **argv) {
    std::string input;
    options_description desc("Available options");
    desc.add_options()
            ("help", "Print usage")
            ("input,i", value(&input), "Include directories");

    positional_options_description positionals;
    positionals.add("Source directory", 1 );

    variables_map vm;
    store(command_line_parser (argc, argv)
               .positional(positionals)
               .options(desc).run (), vm);
    notify (vm);

    if (vm.count ("help") || !vm.count ("value")) {
        std::cerr << desc << "\n";
    }

    return ParseResult::Result_Ok;
}
