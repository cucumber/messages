#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/duration.hpp>

namespace cucumber::messages {

std::string
duration::to_string() const
{
    std::ostringstream oss;

    oss
    << "seconds=" << seconds
    << ", nanos=" << nanos
        ;

    return oss.str();
}

void
duration::to_json(json& j) const
{
    j[camelize("duration")] = json{
        { camelize("seconds"), seconds },
        { camelize("nanos"), nanos }
    };
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
