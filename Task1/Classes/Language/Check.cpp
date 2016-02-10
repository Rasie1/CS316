#include "Check.h"
#include "Unit.h"
#include "Term.h"
#include "Environment.h"
#include "Boolean.h"

const std::string Check::label = "?";

std::string Check::toString() const
{
    //todo
    throw 0;
    return label;
}

std::shared_ptr<Expression> Check::eval(Environment& env)
{
    bool ret = true;

    for (auto i = std::next(std::begin(arguments)); i != std::end(arguments); ++i)
    {
        ret = ret || env.check((*i)->name);
    }
    return std::make_shared<Boolean>(ret);

}
