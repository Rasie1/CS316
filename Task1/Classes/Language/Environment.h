#pragma once
#include <map>
#include <memory>

class Term;

class Environment
{
public:
    Environment() {}

private:
    std::multimap<std::shared_ptr<Term>, std::shared_ptr<Term>> links;
};

