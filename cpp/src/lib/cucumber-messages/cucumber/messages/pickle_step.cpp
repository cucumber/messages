#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/pickle_step.hpp>

namespace cucumber::messages {

std::string
pickle_step::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "argument=", argument);
    cucumber::messages::to_string(oss, ", ast_node_ids=", ast_node_ids);
    cucumber::messages::to_string(oss, ", id=", id);
    cucumber::messages::to_string(oss, ", type=", type);
    cucumber::messages::to_string(oss, ", text=", text);

    return oss.str();
}

void
pickle_step::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("argument"), argument);
    cucumber::messages::to_json(j, camelize("ast_node_ids"), ast_node_ids);
    cucumber::messages::to_json(j, camelize("id"), id);
    cucumber::messages::to_json(j, camelize("type"), type);
    cucumber::messages::to_json(j, camelize("text"), text);
}

std::string
pickle_step::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const pickle_step& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const pickle_step& m)
{ m.to_json(j); }

}
