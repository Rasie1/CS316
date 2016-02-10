#pragma once
#include <string>
#include "Parser.h"

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
};

