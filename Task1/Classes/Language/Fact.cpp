#include "Fact.h"
#include "Term.h"
#include "Unit.h"
#include "Environment.h"
#include <numeric>

const std::string Fact::label = "=>";

std::string Fact::toString() const
{
    return std::accumulate(
        std::begin(arguments),
        std::end(arguments), label,
        [](const std::string& acc, const std::shared_ptr<Term>& x){ return acc + " " + x->toString(); });
}


std::shared_ptr<Expression> Fact::eval(Environment& env)
{
    for (auto i = std::begin(arguments); i != std::end(arguments); ++i)
    {
        env.fact((*i)->name);
    }
    return std::make_shared<Unit>();
}
