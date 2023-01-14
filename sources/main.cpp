#include <iostream>

#include "commandlineparser.h"

int main(int argc, char **argv) {

    CommandLineParser parser;
    switch (parser.parseArguments(argc, argv)) {
    case ParseResult::Result_Ok:
        break;
    case ParseResult::Result_Error:
        break;
    default:
        break;
    }

    return 0;
}
