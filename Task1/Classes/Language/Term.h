#pragma once
#include "Expression.h"
#include <string>

class Term :
	public Expression
{
public:
	Term(const std::string& name) :
		name(name) {}

	virtual std::string toString() const override;

private:
	std::string name;
};

