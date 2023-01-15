#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <list>
#include <string>

class FileUtils {
public:
	static std::list<std::string> getListSourceFilesFromFolder(const std::string& folder);
	static std::string getFileName(const std::string& filePath);
};

#endif 