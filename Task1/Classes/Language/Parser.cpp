#include "Parser.h"
#include "Expression.h"
#include "Term.h"
#include "Rule.h"
#include "Fact.h"
#include "Check.h"
#include <sstream>
#include <iterator>
#include <algorithm>

std::vector<std::string> tokenize(const std::string& input)
{
    std::istringstream ss(input);
    return std::vector<std::string>(
        std::istream_iterator<std::string>(ss),
        std::istream_iterator<std::string>());
}

std::shared_ptr<Expression> Parser::parse(const std::string& input)
{
    size_t p = input.find(Rule::label);
    // case for "Rule" and "Fact"
    if (p != input.npos)
    {
        auto beforeLabel = input.substr(0, p);
        auto afterLabel = input.substr(
            p + Rule::label.size(),
            p + Rule::label.size() - input.size());

        auto tokensBefore = tokenize(beforeLabel);

        // case for "Fact"
        if (tokensBefore.size() == 0)
        {
            auto tokensAfter = tokenize(afterLabel);
            if (tokensAfter.size() != 1)
                throw 1;

            return std::make_shared<Fact>(
                std::vector<std::shared_ptr<Term>>{ std::make_shared<Term>(tokensAfter[0]) });
        }

        if (tokensBefore.size() != 1)
            throw 0;

        // case for "Rule"

        auto tokensAfter = tokenize(afterLabel);

        std::vector<std::shared_ptr<Term>> argumentToRule;
        argumentToRule.push_back(std::make_shared<Term>(tokensBefore[0]));
        std::transform(
            std::begin(tokensAfter),
            std::end(tokensAfter),
            std::back_inserter(argumentToRule),
            [](const std::string& token){ return std::make_shared<Term>(token); });

        return std::make_shared<Rule>(std::vector<std::shared_ptr<Term>>(argumentToRule));
    }
    // case for "Check"
    else
    {
        auto tokens = tokenize(input);

        if (tokens.size() == 1)
        {
            return std::make_shared<Check>(std::make_shared<Term>(tokens[0]));
        }
        else if (input == "help")
        {
            return nullptr;
        }
        else
        {
            throw std::logic_error("Couln't parse input");
            return nullptr;
        }
    }
}
