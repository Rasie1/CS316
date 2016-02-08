#pragma once
#include "Operation.h"

class Check :
	public Operation
{
public:
	Check(const std::vector<std::shared_ptr<Term>>& arguments) :
		Operation(arguments) {}

	static const std::string label;
	std::string toString() const override;
};

