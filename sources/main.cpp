#include <iostream>

#include "commandlineparser.h"
#include "fileutils.h"
#include "include_guard/includeguard.h"

int main(int argc, char **argv) {

    CommandLineParser parser;
    if (parser.parseArguments(argc, argv) != ParseResult::Result_Error) {

        auto& sourceFolder = parser.getSourceFolder();
        auto listIncudeDirs = parser.getListIncudeDirs();
        auto listSourceFiles = FileUtils::getListSourceFilesFromFolder(sourceFolder);

        IncludeGuard guard;
        guard.setSourceFiles(listSourceFiles);
        guard.createIncludeGraph();
        guard.printIncludeGraph();

    }

    return 0;
}
