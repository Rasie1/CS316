#pragma once
#include "Expression.h"
#include <vector>

class Term;
class Operation :
	public Expression
{
public:
	Operation(const std::vector<std::shared_ptr<Term>>& arguments) :
		arguments(arguments) {}

	std::vector<std::shared_ptr<Term>> getArguments() const;

private:
	std::vector<std::shared_ptr<Term>> arguments;
};

