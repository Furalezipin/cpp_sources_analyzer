#ifndef SOURCEFILE_H
#define SOURCEFILE_H

#include <string>
#include <list>

class SourceFile {
public:
	SourceFile(const std::string& path);

	const std::list<std::string>& getGlobalIncludes();
	const std::list<std::string>& getLocalIncludes();

private:
	std::list<std::string> m_listLocalIncludes;
	std::list<std::string> m_listGlobalIncludes;

};


#endif