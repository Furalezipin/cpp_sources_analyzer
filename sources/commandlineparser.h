#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H

#include <vector>
#include <string>

enum class ParseResult {
    Result_Ok,
    Result_Error
};

class CommandLineParser
{
public:
    CommandLineParser();
    const std::string& getSourceFolder();
    const std::vector<std::string>& getListIncudeDirs();
    ParseResult parseArguments(int argc, char **argv);
private:
    std::string m_sourceFolder;
    std::vector<std::string> m_listIncludeDirs;
};

#endif // COMMANDLINEPARSER_H
