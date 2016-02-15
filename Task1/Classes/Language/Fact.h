#pragma once
#include "Operation.h"
class Fact :
    public Operation
{
public:
    Fact(const std::shared_ptr<Term>& argument) :
        Operation({argument}) {}

    std::shared_ptr<Expression> eval(Environment& env) override;

    static const std::string label;
    std::string toString() const override;
};

