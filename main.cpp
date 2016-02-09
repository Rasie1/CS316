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

		repl.process(input, output, shouldContinue);
		
		std::cout << output << std::endl;
	}
	return 0;
}