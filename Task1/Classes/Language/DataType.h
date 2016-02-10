#pragma once
#include "Expression.h"

class DataType :
    public Expression,
    public std::enable_shared_from_this<DataType>
{
public:
    std::shared_ptr<Expression> eval(Environment& env) override;
};

