#pragma once
#include "DataType.h"
#include <string>

class HelpMessage :
    public DataType
{
public:
    HelpMessage() {}

    static const std::string label;

    virtual std::string toString() const override;
};

