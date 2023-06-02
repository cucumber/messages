#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/examples.hpp>

namespace cucumber::messages {

std::string
examples::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "location=", location);
    cucumber::messages::to_string(oss, ", tags=", tags);
    cucumber::messages::to_string(oss, ", keyword=", keyword);
    cucumber::messages::to_string(oss, ", name=", name);
    cucumber::messages::to_string(oss, ", description=", description);
    cucumber::messages::to_string(oss, ", table_header=", table_header);
    cucumber::messages::to_string(oss, ", table_body=", table_body);
    cucumber::messages::to_string(oss, ", id=", id);

    return oss.str();
}

void
examples::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("location"), location);
    cucumber::messages::to_json(j, camelize("tags"), tags);
    cucumber::messages::to_json(j, camelize("keyword"), keyword);
    cucumber::messages::to_json(j, camelize("name"), name);
    cucumber::messages::to_json(j, camelize("description"), description);
    cucumber::messages::to_json(j, camelize("table_header"), table_header);
    cucumber::messages::to_json(j, camelize("table_body"), table_body);
    cucumber::messages::to_json(j, camelize("id"), id);
}

std::string
examples::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const examples& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const examples& m)
{ m.to_json(j); }

}
