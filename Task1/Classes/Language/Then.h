#pragma once
#include "Operation.h"

class Then :
    public Operation
{
public:
    Then(const std::vector<std::shared_ptr<Term>>& arguments) :
        Operation(arguments) {}

    std::shared_ptr<Expression> eval(Environment& env) override;

    std::string toString() const override;
    static std::string label;

};

