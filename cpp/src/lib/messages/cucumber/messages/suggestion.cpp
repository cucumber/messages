#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/suggestion.hpp>

namespace cucumber::messages {

std::string
suggestion::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "id=", id);
    cucumber::messages::to_string(oss, ", pickle_step_id=", pickle_step_id);
    cucumber::messages::to_string(oss, ", snippets=", snippets);

    return oss.str();
}

void
suggestion::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("id"), id);
    cucumber::messages::to_json(j, camelize("pickle_step_id"), pickle_step_id);
    cucumber::messages::to_json(j, camelize("snippets"), snippets);
}

std::string
suggestion::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const suggestion& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const suggestion& m)
{ m.to_json(j); }

}
