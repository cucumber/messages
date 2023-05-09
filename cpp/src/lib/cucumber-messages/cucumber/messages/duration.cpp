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

std::ostream&
operator<<(std::ostream& os, const duration& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const duration& m)
{
    j = json{
        { "seconds", m.seconds },
        { "nanos", m.nanos }
    };
}

}
