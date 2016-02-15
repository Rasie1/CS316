#pragma once
#include "Operation.h"

class FromFile :
    public Operation
{
public:
    FromFile(const std::shared_ptr<Term>& argument) :
        Operation({argument}) {}

    std::shared_ptr<Expression> eval(Environment& env) override;

    std::string toString() const override;
    static std::string label;

};

