#include "REPL.h"
#include <string>
#include "Expression.h"

REPL::REPL()
{
}

void REPL::process(const std::string& input, 
				   std::string& output,
				   bool& shouldContinue)
{
	auto result = parser.parse(input);

	output = result->toString();
}

REPL::~REPL()
{
}
