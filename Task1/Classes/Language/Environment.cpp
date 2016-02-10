#include "Environment.h"

void Environment::fact(const std::string& term)
{
    truth.insert(term);
}

void Environment::fillWithTrue(const std::string& term)
{
    fact(term);
    for (auto &x : links[term])
        if (!check(x))
            fillWithTrue(x);
}

void Environment::then(const std::string& from, const std::string& to)
{
    if (check(from))
        fillWithTrue(to);

    links[from].insert(to);
}

bool Environment::check(const std::string& term)
{
    return truth.find(term) != std::end(truth);
}
