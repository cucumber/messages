#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/hook.hpp>

namespace cucumber::messages {

std::string
hook::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "id=", id);
    cucumber::messages::to_string(oss, ", name=", name);
    cucumber::messages::to_string(oss, ", source_reference=", source_reference);
    cucumber::messages::to_string(oss, ", tag_expression=", tag_expression);

    return oss.str();
}

void
hook::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("id"), id);
    cucumber::messages::to_json(j, camelize("name"), name);
    cucumber::messages::to_json(j, camelize("source_reference"), source_reference);
    cucumber::messages::to_json(j, camelize("tag_expression"), tag_expression);
}

std::string
hook::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const hook& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const hook& m)
{ m.to_json(j); }

}
