#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/step_definition.hpp>

namespace cucumber::messages {

std::string
step_definition::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "id=", id);
    cucumber::messages::to_string(oss, ", pattern=", pattern);
    cucumber::messages::to_string(oss, ", source_reference=", source_reference);

    return oss.str();
}

void
step_definition::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("id"), id);
    cucumber::messages::to_json(j, camelize("pattern"), pattern);
    cucumber::messages::to_json(j, camelize("source_reference"), source_reference);
}

std::string
step_definition::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const step_definition& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const step_definition& m)
{ m.to_json(j); }

}
