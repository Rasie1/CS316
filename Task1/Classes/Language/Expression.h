#pragma once
#include <memory>
#include <string>

class Environment;

class Expression
{
public:
    Expression() {}

    virtual std::shared_ptr<Expression> eval(Environment& env) = 0;
    virtual std::string toString() const = 0;
};

