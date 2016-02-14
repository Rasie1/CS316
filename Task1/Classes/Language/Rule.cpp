#include "Rule.h"
#include <numeric>
#include "Term.h"
#include "Unit.h"
#include "Environment.h"

std::string Rule::label = ":-";

std::string Rule::toString() const
{
    std::string ret = arguments[0]->toString() + " " + label;

    return std::accumulate(
        std::next(std::begin(arguments)),
        std::end(arguments), arguments[0]->toString() + " " + label,
        [](const std::string& acc, const std::shared_ptr<Term>& x){ return acc + " " + x->toString(); });
}

std::shared_ptr<Expression> Rule::eval(Environment& env)
{
    std::set<std::string> conj;
    for (auto i = std::next(std::begin(arguments)); i != std::end(arguments); ++i)
    {
        conj.insert((*i)->name);
    }
    env.rule(conj, (*std::begin(arguments))->name);
    return std::make_shared<Unit>();
}
