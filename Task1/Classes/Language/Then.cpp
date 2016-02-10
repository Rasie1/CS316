#include "Then.h"
#include <numeric>
#include "Term.h"
#include "Unit.h"
#include "Environment.h"

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

std::shared_ptr<Expression> Then::eval(Environment& env)
{
    return std::make_shared<Unit>();
}
