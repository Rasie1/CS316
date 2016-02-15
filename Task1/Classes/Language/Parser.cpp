#include "Parser.h"
#include "Expression.h"
#include "Term.h"
#include "Rule.h"
#include "Fact.h"
#include "Check.h"
#include "HelpMessage.h"
#include "FromFile.h"
#include <sstream>
#include <iterator>
#include <algorithm>

const std::string parseErrorMsg = "Couldn't parse input";

std::vector<std::string> tokenize(const std::string& input)
{
    std::istringstream ss(input);
    return std::vector<std::string>(
        std::istream_iterator<std::string>(ss),
        std::istream_iterator<std::string>());
}

std::shared_ptr<Expression> Parser::parse(const std::string& input)
{
    // Help msg
    if (input == HelpMessage::label)
        return std::make_shared<HelpMessage>();
    // Case for "Rule"
    size_t p = input.find(Rule::label);
    if (p != input.npos)
    {
        auto beforeLabel = input.substr(0, p);
        auto afterLabel = input.substr(
            p + Rule::label.size(),
            p + Rule::label.size() - input.size());

        auto tokensBefore = tokenize(beforeLabel);
        auto tokensAfter = tokenize(afterLabel);

        if (tokensAfter.size() == 0 || tokensBefore.size() != 1)
            throw std::logic_error(parseErrorMsg + "(" + input + ")");

        std::vector<std::shared_ptr<Term>> argumentToRule;
        argumentToRule.push_back(std::make_shared<Term>(tokensBefore[0]));
        std::transform(
            std::begin(tokensAfter),
            std::end(tokensAfter),
            std::back_inserter(argumentToRule),
            [](const std::string& token){ return std::make_shared<Term>(token); });

        return std::make_shared<Rule>(std::vector<std::shared_ptr<Term>>(argumentToRule));
    }
    // case for "fromFile"
    p = input.find(FromFile::label);
    if (p != input.npos)
    {
        auto afterLabel = input.substr(
            p + FromFile::label.size(),
            p + FromFile::label.size() - input.size());
        auto tokens = tokenize(afterLabel);
        if (tokens.size() != 1)
            throw std::logic_error(parseErrorMsg + "(" + input + ")");

        return std::make_shared<FromFile>(std::make_shared<Term>(tokens[0]));
    }
    p = input.find(Check::label);
    // case for "Check"
    if (p != input.npos)
    {

        auto beforeLabel = input.substr(0, p);
        auto tokens = tokenize(beforeLabel);

        if (tokens.size() == 1)
            return std::make_shared<Check>(std::make_shared<Term>(tokens[0]));
        else
            throw std::logic_error(parseErrorMsg + "(" + input + ")");
    }
    // case for "Fact"
    else
    {
        auto tokens = tokenize(input);

        if (tokens.size() == 1)
            return std::make_shared<Fact>(std::make_shared<Term>(tokens[0]));
        else
            throw std::logic_error(parseErrorMsg + "(" + input + ")");
    }
}
