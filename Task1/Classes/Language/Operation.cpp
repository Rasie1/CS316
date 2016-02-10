#include "Operation.h"

std::vector<std::shared_ptr<Term>> Operation::getArguments() const
{
	return arguments;
}