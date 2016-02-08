#pragma once
#include <memory>
#include <string>

class Expression;
class Parser
{
public:
	Parser();

	std::shared_ptr<Expression> parse(const std::string input);

	~Parser();
};

