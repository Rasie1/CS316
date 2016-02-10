#include "Parser.h"
#include "Expression.h"
#include "Term.h"
#include "Then.h"
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
    size_t p = input.find(Then::label);
    // case for "Then" and "Fact"
    if (p != input.npos)
    {
        auto beforeLabel = input.substr(0, p);
        auto afterLabel = input.substr(
            p + Then::label.size(),
            p + Then::label.size() - input.size());

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

        // case for "Then"

        auto tokensAfter = tokenize(afterLabel);

        std::vector<std::shared_ptr<Term>> argumentToThen;
        argumentToThen.push_back(std::make_shared<Term>(tokensBefore[0]));
        std::transform(
            std::begin(tokensAfter),
            std::end(tokensAfter),
            std::back_inserter(argumentToThen),
            [](const std::string& token){ return std::make_shared<Term>(token); });

        return std::make_shared<Then>(std::vector<std::shared_ptr<Term>>(argumentToThen));
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
