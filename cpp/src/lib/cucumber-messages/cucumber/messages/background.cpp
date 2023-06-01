#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/background.hpp>

namespace cucumber::messages {

std::string
background::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "location=", location);
    cucumber::messages::to_string(oss, ", keyword=", keyword);
    cucumber::messages::to_string(oss, ", name=", name);
    cucumber::messages::to_string(oss, ", description=", description);
    cucumber::messages::to_string(oss, ", steps=", steps);
    cucumber::messages::to_string(oss, ", id=", id);

    return oss.str();
}

void
background::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("location"), location);
    cucumber::messages::to_json(j, camelize("keyword"), keyword);
    cucumber::messages::to_json(j, camelize("name"), name);
    cucumber::messages::to_json(j, camelize("description"), description);
    cucumber::messages::to_json(j, camelize("steps"), steps);
    cucumber::messages::to_json(j, camelize("id"), id);
}

std::string
background::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const background& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const background& m)
{ m.to_json(j); }

}
