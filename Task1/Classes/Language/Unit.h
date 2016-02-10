#pragma once
#include "DataType.h"

class Unit :
    public DataType
{
public:
    Unit() {}

    virtual std::string toString() const override;
};

