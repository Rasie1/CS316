#include "HelpMessage.h"

const std::string HelpMessage::label = "help";

std::string HelpMessage::toString() const
{
    return R"HELPMSG(====== help ======
Task Made by Vsevolod Kvachev, 3.9
Rules are formed like that:
    a :- b c
Check if term is true:
    a?
Make term true:
    a
==================)HELPMSG";
}
