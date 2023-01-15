#include "sourcefile.h"
#include "../fileutils.h"

#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>

constexpr auto INCLUDE_DIRECTIVE = "#include" ;
constexpr auto COMMENTARY = "//";
constexpr auto MULTIROW_COMMENTARY_BEGIN = "/*";
constexpr auto MULTIROW_COMMENTARY_END = "*/";

using namespace boost::algorithm;

SourceFile::SourceFile(const std::string& path) :
    m_path(path), m_fileName(FileUtils::getFileName(path)), m_isParsed(false)
{
}

const std::list<std::string>& SourceFile::getGlobalIncludes() {
    if (!m_isParsed) parse();
	return m_listGlobalIncludes;
}

const std::list<std::string>& SourceFile::getLocalIncludes() {
    if (!m_isParsed) parse();
    return m_listLocalIncludes;
}

const std::string& SourceFile::getFileName() {
    return m_fileName;
}

const std::string& SourceFile::getFilePath() {
    return m_path;
}

void SourceFile::parse() {

    std::string line;
    std::ifstream in(m_path);

    if (in.is_open()) {
        bool inCommentaryBlock = false;

        while (getline(in, line))
        {
            trim(line);

            if (starts_with(line, MULTIROW_COMMENTARY_BEGIN)) inCommentaryBlock = true;

            if (starts_with(line, MULTIROW_COMMENTARY_END)) inCommentaryBlock = false;

            if (inCommentaryBlock || starts_with(line, COMMENTARY)) continue;

            if (starts_with(line, INCLUDE_DIRECTIVE)) {
                auto it = std::find(line.begin(), line.end(), '<');
                if (it != line.end()) {
                    auto it2 = std::find(it, line.end(), '>');
                    m_listGlobalIncludes.emplace_back(++it, it2);
                }
                else {
                    auto it1 = std::find(line.begin(), line.end(), '"');;
                    auto it2 = std::find(++it1, line.end(), '"');
                    m_listLocalIncludes.emplace_back(it1, it2);
                }
            };
        }
    }
    else {
        std::cerr << "Cannot open file " << m_path << "\n";
    }
    in.close();
    m_isParsed = true;
}

