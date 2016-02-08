#include "Then.h"
#include "Term.h"

std::string Then::label = "=>";

std::string Then::toString() const
{
	auto args = this->getArguments();
	
	std::string ret = args[0]->toString() + " " + label;

	for (auto i = std::next(std::begin(args)); i != std::end(args); ++i)
		ret += " " + (*i)->toString();

	return ret;
}