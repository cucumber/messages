#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/rule_child.hpp>

namespace cucumber::messages {

std::string
rule_child::to_string() const
{
    std::ostringstream oss;

    oss
    << "background=" << background
    << ", scenario=" << scenario
        ;

    return oss.str();
}

void
rule_child::to_json(json& j) const
{
    j = json{
        { "background", background },
        { "scenario", scenario }
    };
}

std::string
rule_child::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const rule_child& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const rule_child& m)
{ m.to_json(j); }

}
