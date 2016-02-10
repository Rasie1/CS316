#pragma once
#include "Expression.h"
#include <vector>

class Term;
class Operation :
    public Expression
{
public:
    Operation(const std::vector<std::shared_ptr<Term>>& arguments) :
        arguments(arguments) {}

    const std::vector<std::shared_ptr<Term>> arguments;
};

