#include "Check.h"
#include "Unit.h"

const std::string Check::label = "?";

std::string Check::toString() const
{
    //todo
    throw 0;
    return label;
}

std::shared_ptr<Expression> Check::eval(Environment& env)
{
    return std::make_shared<Unit>();
}
