#include "FromFile.h"
#include <numeric>
#include "Term.h"
#include "Unit.h"
#include "Environment.h"
#include "Parser.h"
#include <fstream>

std::string FromFile::label = "fromFile";

std::string FromFile::toString() const
{
    return std::accumulate(
        std::begin(arguments),
        std::end(arguments), label,
        [](const std::string& acc, const std::shared_ptr<Term>& x){ return acc + " " + x->toString(); });
}

std::shared_ptr<Expression> FromFile::eval(Environment& env)
{
    try
    {
        Environment old = env;
        Parser parser;
        std::string line;
        std::ifstream infile(arguments[0]->toString());
        if (!infile.is_open())
            throw std::logic_error("Couldn't open file");
        try
        {
            while (std::getline(infile, line))
            {
                auto result = parser.parse(line);
                result->eval(env);
            }
        }
        catch (const std::logic_error& e)
        {
            env = old;
            throw std::logic_error(std::string("Couldn't evaluate code from file: ") + e.what());
        }
    }
    catch (const std::ifstream::failure& e)
    {
        throw std::logic_error("Couldn't open file");
    }

    return std::make_shared<Unit>();
}
