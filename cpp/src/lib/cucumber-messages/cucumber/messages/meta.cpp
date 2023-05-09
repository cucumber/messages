#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/meta.hpp>

namespace cucumber::messages {

std::string
meta::to_string() const
{
    std::ostringstream oss;

    oss
    << "protocol_version=" << protocol_version
    << ", implementation=" << implementation
    << ", runtime=" << runtime
    << ", os=" << os
    << ", cpu=" << cpu
    << ", ci=" << ci
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const meta& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const meta& m)
{
    j = json{
        { "protocol_version", m.protocol_version },
        { "implementation", m.implementation },
        { "runtime", m.runtime },
        { "os", m.os },
        { "cpu", m.cpu },
        { "ci", m.ci }
    };
}

}
