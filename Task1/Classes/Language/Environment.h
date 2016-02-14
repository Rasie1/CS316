#pragma once
#include <set>
#include <map>
#include <memory>
#include <string>

class Term;

class Environment
{
public:
    Environment() {}

    void fact(const std::string& term);
    void rule(const std::set<std::string>& from, const std::string& to);
    bool check(const std::string& term);

private:
    std::set<std::string> used;
    std::set<std::string> truth;
    std::map<std::string, std::set<std::set<std::string>>> links;
};

