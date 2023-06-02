#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/scenario.hpp>

namespace cucumber::messages {

std::string
scenario::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "location=", location);
    cucumber::messages::to_string(oss, ", tags=", tags);
    cucumber::messages::to_string(oss, ", keyword=", keyword);
    cucumber::messages::to_string(oss, ", name=", name);
    cucumber::messages::to_string(oss, ", description=", description);
    cucumber::messages::to_string(oss, ", steps=", steps);
    cucumber::messages::to_string(oss, ", examples=", examples);
    cucumber::messages::to_string(oss, ", id=", id);

    return oss.str();
}

void
scenario::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("location"), location);
    cucumber::messages::to_json(j, camelize("tags"), tags);
    cucumber::messages::to_json(j, camelize("keyword"), keyword);
    cucumber::messages::to_json(j, camelize("name"), name);
    cucumber::messages::to_json(j, camelize("description"), description);
    cucumber::messages::to_json(j, camelize("steps"), steps);
    cucumber::messages::to_json(j, camelize("examples"), examples);
    cucumber::messages::to_json(j, camelize("id"), id);
}

std::string
scenario::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const scenario& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const scenario& m)
{ m.to_json(j); }

}
