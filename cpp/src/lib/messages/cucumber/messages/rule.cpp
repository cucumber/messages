#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/rule.hpp>

namespace cucumber::messages {

std::string
rule::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "location=", location);
    cucumber::messages::to_string(oss, ", tags=", tags);
    cucumber::messages::to_string(oss, ", keyword=", keyword);
    cucumber::messages::to_string(oss, ", name=", name);
    cucumber::messages::to_string(oss, ", description=", description);
    cucumber::messages::to_string(oss, ", children=", children);
    cucumber::messages::to_string(oss, ", id=", id);

    return oss.str();
}

void
rule::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("location"), location);
    cucumber::messages::to_json(j, camelize("tags"), tags);
    cucumber::messages::to_json(j, camelize("keyword"), keyword);
    cucumber::messages::to_json(j, camelize("name"), name);
    cucumber::messages::to_json(j, camelize("description"), description);
    cucumber::messages::to_json(j, camelize("children"), children);
    cucumber::messages::to_json(j, camelize("id"), id);
}

std::string
rule::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const rule& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const rule& m)
{ m.to_json(j); }

}
