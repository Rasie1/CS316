#pragma once
#include <set>
#include <map>
#include <memory>

class Term;

class Environment
{
public:
    Environment() {}

    void fact(const std::string& term);
    void then(const std::string& from, const std::string& to);
    bool check(const std::string& term);

private:
    void fillWithTrue(const std::string& term);

    std::set<std::string> truth;
    std::map<std::string, std::set<std::string>> links;
};

