#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/comment.hpp>

namespace cucumber::messages {

std::string
comment::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "location=", location);
    cucumber::messages::to_string(oss, ", text=", text);

    return oss.str();
}

void
comment::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("location"), location);
    cucumber::messages::to_json(j, camelize("text"), text);
}

std::string
comment::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const comment& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const comment& m)
{ m.to_json(j); }

}
