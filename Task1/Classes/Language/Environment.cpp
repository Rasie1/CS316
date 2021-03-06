#include "Environment.h"

void Environment::fact(const std::string& term)
{
    truth.insert(term);
    used.clear();
}


void Environment::rule(const std::set<std::string>& from, const std::string& to)
{
    links[to].insert(from);
    used.clear();
}

bool Environment::check(const std::string& term)
{
    if (truth.find(term) != truth.end())
        return true;
    for (auto &conj : links[term])
    {
        if (conj.size() == 0)
            continue;

        bool isTermTrue = true;
        for (auto &x : conj)
        {
            used.insert(x);
            if (truth.find(x) != truth.end())
                continue;
            if (used.find(x) != used.end() || !check(x))
            {
                isTermTrue = false;
                break;
            }
        }
        if (isTermTrue)
            return true;
    }
    return false;
}
