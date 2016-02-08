#pragma once
#include <string>

class REPL
{
public:
	REPL();

	void process(const std::string& input, 
		         std::string& output, 
				 bool& shouldContinue);

	~REPL();

private:
};

