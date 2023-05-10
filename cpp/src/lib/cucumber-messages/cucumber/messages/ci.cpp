#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/ci.hpp>

namespace cucumber::messages {

std::string
ci::to_string() const
{
    std::ostringstream oss;

    oss
    << "name=" << name
    << ", url=" << url
    << ", build_number=" << build_number
    << ", git=" << git
        ;

    return oss.str();
}

void
ci::to_json(json& j) const
{
    j[camelize("ci")] = json{
        { camelize("name"), name },
        { camelize("url"), url },
        { camelize("build_number"), build_number },
        { camelize("git"), git }
    };
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
