#ifndef SOURCEFILE_H
#define SOURCEFILE_H

#include <string>
#include <list>

class SourceFile {
public:
	SourceFile(const std::string& path);

	const std::list<std::string>& getGlobalIncludes();
	const std::list<std::string>& getLocalIncludes();

	const std::string& getFileName();
	const std::string& getFilePath();

private:
	std::string m_path;
	std::string m_fileName;

	bool m_isParsed;
	std::list<std::string> m_listLocalIncludes;
	std::list<std::string> m_listGlobalIncludes;

	void parse();

};


#endif