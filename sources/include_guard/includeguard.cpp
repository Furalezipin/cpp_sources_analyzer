#include "includeguard.h"

#include <fstream>
#include <iostream>

IncludeGuard::IncludeGuard() {
}

IncludeGuard::IncludeGuard(const std::list<std::string>& sourceFiles, const std::list<std::string>& includeDirs) {
}

void IncludeGuard::setIncludeDirs(const std::list<std::string>& includeDirs) {
}

void IncludeGuard::setSourceFiles(const std::list<std::string>& sourceFiles) {
	
	for (auto& file : sourceFiles) {

		        std::string line;
        std::ifstream in(file);
        if (in.is_open())
        {
            while (getline(in, line))
            {
                std::cout << line << std::endl;
            }
        }
        else {
            std::cerr << "Cannot open file " << file  << "\n";
        }
        in.close();

        std::cout << "End of program" << std::endl;

	}

}

void IncludeGuard::createIncludeGraph() {
}

void IncludeGuard::printIncludeGraph() {
}
