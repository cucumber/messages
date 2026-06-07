#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/ci.hpp>

namespace cucumber::messages {

std::string
ci::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "name=", name);
    cucumber::messages::to_string(oss, ", url=", url);
    cucumber::messages::to_string(oss, ", build_number=", build_number);
    cucumber::messages::to_string(oss, ", git=", git);

    return oss.str();
}

void
ci::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("name"), name);
    cucumber::messages::to_json(j, camelize("url"), url);
    cucumber::messages::to_json(j, camelize("build_number"), build_number);
    cucumber::messages::to_json(j, camelize("git"), git);
}

std::string
ci::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const ci& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const ci& m)
{ m.to_json(j); }

}
