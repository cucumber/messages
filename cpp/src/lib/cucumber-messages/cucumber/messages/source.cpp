#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/source.hpp>

namespace cucumber::messages {

std::string
source::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "uri=", uri);
    cucumber::messages::to_string(oss, ", data=", data);
    cucumber::messages::to_string(oss, ", media_type=", media_type);

    return oss.str();
}

void
source::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("uri"), uri);
    cucumber::messages::to_json(j, camelize("data"), data);
    cucumber::messages::to_json(j, camelize("media_type"), media_type);
}

std::string
source::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const source& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const source& m)
{ m.to_json(j); }

}
