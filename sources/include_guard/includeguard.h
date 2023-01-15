#ifndef INCLUDEGUARD_H
#define INCLUDEGUARD_H

#include <list>
#include <string>

#include "sourcefile.h"

class IncludeGuard {
public:
	IncludeGuard();
        IncludeGuard(const std::list<std::string>& sourceFiles, std::list<std::string>&& includeDirs,
                     const std::string& self_dir);

        void setIncludeDirs(std::list<std::string> &&includeDirs);
	void setSourceFiles(const std::list<std::string>& sourceFiles);

	void createIncludeGraph();
	void printIncludeGraph();

private:
	std::list<SourceFile> m_sourceFiles;
        std::list<std::string> m_includeDir;
        std::string m_selfDir;
	void parseSourceFiles(const std::list<std::string>& sourceFiles);

};

#endif
