#include "sourcefile.h"

#include <fstream>
#include <iostream>

#include <boost/algorithm/string.hpp>

SourceFile::SourceFile(const std::string& path) {
	
    std::string line;
    std::ifstream in(path);

    if (in.is_open())
    {
        while (getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    else {
        std::cerr << "Cannot open file " << path << "\n";
    }
    in.close();

}

const std::list<std::string>& SourceFile::getGlobalIncludes() {
	return m_listGlobalIncludes;
}

const std::list<std::string>& SourceFile::getLocalIncludes() {
	return m_listLocalIncludes;
}

