#pragma once
#include <string>
#include "Parser.h"
#include "Environment.h"

class REPL
{
public:
    REPL();

    void process(const std::string& input,
                 std::string& output,
                 bool& shouldContinue);

    ~REPL();

private:
    Parser parser;
    Environment env;
};

