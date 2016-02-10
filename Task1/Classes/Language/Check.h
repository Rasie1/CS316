#pragma once
#include "Operation.h"

class Check :
    public Operation
{
public:
    Check(const std::shared_ptr<Term>& arg);

    std::shared_ptr<Expression> eval(Environment& env) override;

    static const std::string label;
    std::string toString() const override;
};

