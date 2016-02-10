#include "Check.h"
#include "Unit.h"
#include "Term.h"
#include "Environment.h"
#include "Boolean.h"

const std::string Check::label = "?";

Check::Check(const std::shared_ptr<Term>& term) :
    Operation({term})
{
}

std::string Check::toString() const
{
    return arguments[0]->toString() + "?";
}

std::shared_ptr<Expression> Check::eval(Environment& env)
{
    bool ret = false;

    for (auto i = std::begin(arguments); i != std::end(arguments); ++i)
    {
        ret = ret || env.check((*i)->name);
    }
    return std::make_shared<Boolean>(ret);

}
