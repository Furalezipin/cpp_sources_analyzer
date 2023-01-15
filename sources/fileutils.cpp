#include "fileutils.h"

#include <iostream>
#include <unordered_set>

#include <boost/filesystem.hpp>
#include <boost/system/error_code.hpp>

using namespace boost::filesystem;
using boost::system::error_code;

std::list<std::string> FileUtils::getListSourceFilesFromFolder(const std::string& folder) {
    std::unordered_set<std::string> extensions({ ".h", ".hpp", ".cpp", ".cxx", ".c" });
    std::list<std::string> listFiles;

    if (!exists(folder) || !is_directory(folder)) return listFiles;

    recursive_directory_iterator iter(folder);
    recursive_directory_iterator end;

    while (iter != end) {   
        if (!is_directory(iter->path()) && extensions.find(iter->path().extension().string()) != extensions.end()) {
            listFiles.emplace_back(iter->path().string());
        }

        error_code ec;
        iter.increment(ec);
        if (ec) {
            std::cerr << "Error While Accessing : " << iter->path().string() << " :: " << ec.message() << '\n';
        }
    }

	return listFiles;
}