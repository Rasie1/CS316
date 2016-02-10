#pragma once
#include "DataType.h"
#include <string>

class Boolean :
    public DataType
{
public:
    Boolean(bool value) :
        value(value) {}

    virtual std::string toString() const override;

    const bool value;
};

