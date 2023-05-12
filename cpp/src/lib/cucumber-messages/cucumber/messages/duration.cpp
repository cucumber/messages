#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/duration.hpp>

namespace cucumber::messages {

std::string
duration::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "seconds=", seconds);
    cucumber::messages::to_string(oss, ", nanos=", nanos);

    return oss.str();
}

void
duration::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("seconds"), seconds);
    cucumber::messages::to_json(j, camelize("nanos"), nanos);
}

std::string
duration::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const duration& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const duration& m)
{ m.to_json(j); }

}
