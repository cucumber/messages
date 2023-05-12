#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/location.hpp>

namespace cucumber::messages {

std::string
location::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "line=", line);
    cucumber::messages::to_string(oss, ", column=", column);

    return oss.str();
}

void
location::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("line"), line);
    cucumber::messages::to_json(j, camelize("column"), column);
}

std::string
location::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const location& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const location& m)
{ m.to_json(j); }

}
