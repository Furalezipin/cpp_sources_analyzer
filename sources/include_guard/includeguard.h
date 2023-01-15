#ifndef INCLUDEGUARD_H
#define INCLUDEGUARD_H

#include <list>
#include <string>

class IncludeGuard {
public:
	IncludeGuard();
	IncludeGuard(const std::list<std::string>& sourceFiles, const std::list<std::string>& includeDirs);

	void setIncludeDirs(const std::list<std::string>& includeDirs);
	void setSourceFiles(const std::list<std::string>& sourceFiles);

	void createIncludeGraph();
	void printIncludeGraph();

private:

};

#endif