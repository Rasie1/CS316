#pragma once
#include "Operation.h"

class Then final :
	public Operation
{
public:
	Then(const std::vector<std::shared_ptr<Term>>& arguments) :
		Operation(arguments) {}

	std::string toString() const override;
	static std::string label;

};

