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
		std::cin >> input;

		repl.process(input, output, shouldContinue);
		
		std::cout << output << std::endl;
	}
	return 0;
}