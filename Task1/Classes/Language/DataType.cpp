#include "DataType.h"


std::shared_ptr<Expression> DataType::eval(Environment& env)
{
    return shared_from_this();
}
