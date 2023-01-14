#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H

enum class ParseResult {
    Result_Ok,
    Result_HelpRequested,
    Result_Error
};

class CommandLineParser
{
public:
    CommandLineParser();

    ParseResult parseArguments(int argc, char **argv);
};

#endif // COMMANDLINEPARSER_H
