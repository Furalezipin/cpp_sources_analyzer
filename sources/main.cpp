#include <iostream>

#include "commandlineparser.h"
#include "fileutils.h"
#include "include_guard/includeguard.h"

int main(int argc, char **argv) {

    CommandLineParser parser;
    if (parser.parseArguments(argc, argv) != ParseResult::Result_Error) {

        auto& sourceFolder = parser.getSourceFolder();
        auto& listIncudeDirs = parser.getListIncudeDirs();

        std::cout << sourceFolder << "\n";
        std::cout << listIncudeDirs.size() << "\n";

        auto listSourceFiles = std::move(FileUtils::getListSourceFilesFromFolder(sourceFolder));
        for (auto& file : listSourceFiles) {
            std::cout << file << "\n";
        }

        IncludeGuard guard;
        guard.setSourceFiles(listSourceFiles);
        guard.createIncludeGraph();
        guard.printIncludeGraph();

    }

    return 0;
}
