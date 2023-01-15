#include <iostream>

#include "commandlineparser.h"
#include "fileutils.h"

int main(int argc, char **argv) {

    CommandLineParser parser;
    if (parser.parseArguments(argc, argv) != ParseResult::Result_Error) {

        auto& sourceFolder = parser.getSourceFolder();
        auto& listIncudeDirs = parser.getListIncudeDirs();

        std::cout << sourceFolder << "\n";
        std::cout << listIncudeDirs.size() << "\n";

        auto listSourceFiles = FileUtils::getListSourceFilesFromFolder(sourceFolder);
        for (auto file : listSourceFiles) {
            std::cout << file << "\n";
        }

    }

    return 0;
}
