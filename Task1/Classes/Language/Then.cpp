#include "Then.h"
#include <numeric>
#include "Term.h"
#include "Unit.h"
#include "Environment.h"

std::string Then::label = "=>";

std::string Then::toString() const
{
    std::string ret = arguments[0]->toString() + " " + label;

    return std::accumulate(
        std::next(std::begin(arguments)),
        std::end(arguments), arguments[0]->toString() + " " + label,
        [](const std::string& acc, const std::shared_ptr<Term>& x){ return acc + " " + x->toString(); });
}

std::shared_ptr<Expression> Then::eval(Environment& env)
{
    for (auto i = std::next(std::begin(arguments)); i != std::end(arguments); ++i)
    {
        env.then((*std::begin(arguments))->name, (*i)->name);
    }
    return std::make_shared<Unit>();
}
