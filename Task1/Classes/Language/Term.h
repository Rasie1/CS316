#pragma once
#include "DataType.h"
#include <string>

class Term :
    public DataType
{
public:
    Term(const std::string& name) :
        name(name) {}

    virtual std::string toString() const override;

    const std::string name;

private:
};

