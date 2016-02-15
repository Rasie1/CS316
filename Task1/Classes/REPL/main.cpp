#include <iostream>
#include <string>
#include "REPL.h"

int main()
{
    REPL repl;

    bool shouldContinue = true;
    while (shouldContinue)
    {
        std::cout << ":> ";
        std::string input, output;

        char line[256];
        std::cin.getline(line, 256);
        input = std::string(line);

        try
        {
            repl.process(input, output, shouldContinue);
            std::cout << output << std::endl;
        }
        catch (const std::logic_error& e)
        {
            std::cout << e.what() << std::endl;
        }

    }

    return 0;
}
