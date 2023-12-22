#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/timestamp.hpp>

namespace cucumber::messages {

std::string
timestamp::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "seconds=", seconds);
    cucumber::messages::to_string(oss, ", nanos=", nanos);

    return oss.str();
}

void
timestamp::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("seconds"), seconds);
    cucumber::messages::to_json(j, camelize("nanos"), nanos);
}

std::string
timestamp::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const timestamp& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const timestamp& m)
{ m.to_json(j); }

}
