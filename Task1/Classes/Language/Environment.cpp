#include "Environment.h"

void Environment::fact(const std::string& term)
{
    truth.insert(term);
}

void Environment::then(const std::string& from, const std::string& to)
{
    links[from].insert(to);
}

bool Environment::check(const std::string& term)
{
    return truth.find(term) != std::end(truth);
}
