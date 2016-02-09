#include "Then.h"
#include "Term.h"
#include <numeric>

std::string Then::label = "=>";

std::string Then::toString() const
{
	auto args = this->getArguments();
	
	std::string ret = args[0]->toString() + " " + label;

	return std::accumulate(
		std::next(std::begin(args)),
		std::end(args), args[0]->toString() + " " + label,
		[](const std::string& acc, const std::shared_ptr<Term>& x){ return acc + " " + x->toString(); });
}