#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/meta.hpp>

namespace cucumber::messages {

std::string
meta::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "protocol_version=", protocol_version);
    cucumber::messages::to_string(oss, ", implementation=", implementation);
    cucumber::messages::to_string(oss, ", runtime=", runtime);
    cucumber::messages::to_string(oss, ", os=", os);
    cucumber::messages::to_string(oss, ", cpu=", cpu);
    cucumber::messages::to_string(oss, ", ci=", ci);

    return oss.str();
}

void
meta::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("protocol_version"), protocol_version);
    cucumber::messages::to_json(j, camelize("implementation"), implementation);
    cucumber::messages::to_json(j, camelize("runtime"), runtime);
    cucumber::messages::to_json(j, camelize("os"), os);
    cucumber::messages::to_json(j, camelize("cpu"), cpu);
    cucumber::messages::to_json(j, camelize("ci"), ci);
}

std::string
meta::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const meta& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const meta& m)
{ m.to_json(j); }

}
