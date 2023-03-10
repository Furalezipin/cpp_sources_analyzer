#include "includeguard.h"

IncludeGuard::IncludeGuard() {
}

IncludeGuard::IncludeGuard(const std::list<std::string>& sourceFiles, std::list<std::string> &&includeDirs, const std::string &self_dir) :
    m_selfDir(self_dir), m_includeDir(std::forward<std::list<std::string>>(includeDirs))
{
	parseSourceFiles(sourceFiles);
}

void IncludeGuard::setIncludeDirs(std::list<std::string>&& includeDirs) {
    m_includeDir = std::forward<std::list<std::string>>(includeDirs);
}

void IncludeGuard::setSourceFiles(const std::list<std::string>& sourceFiles) {
	parseSourceFiles(sourceFiles);
}

void IncludeGuard::createIncludeGraph() {
}

void IncludeGuard::printIncludeGraph() {
}

void IncludeGuard::parseSourceFiles(const std::list<std::string>& sourceFiles) {
	for (auto& file : sourceFiles) {
		m_sourceFiles.emplace_back(file);
	}
}
