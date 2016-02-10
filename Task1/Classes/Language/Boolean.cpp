#include "Boolean.h"

std::string Boolean::toString() const
{
    return value ? "true" : "false";
}
