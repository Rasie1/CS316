#pragma once
#include "Operation.h"
class Fact :
	public Operation
{
public:
	Fact(const std::vector<std::shared_ptr<Term>>& arguments) :
		Operation(arguments) {}

	static const std::string label;
	std::string toString() const override;
};

