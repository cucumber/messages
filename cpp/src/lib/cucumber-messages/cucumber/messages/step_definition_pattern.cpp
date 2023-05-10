#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/step_definition_pattern.hpp>

namespace cucumber::messages {

std::string
step_definition_pattern::to_string() const
{
    std::ostringstream oss;

    oss
    << "source=" << source
    << ", type=" << type
        ;

    return oss.str();
}

void
step_definition_pattern::to_json(json& j) const
{
    j[camelize("step_definition_pattern")] = json{
        { camelize("source"), source },
        { camelize("type"), type }
    };
}

std::string
step_definition_pattern::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const step_definition_pattern& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const step_definition_pattern& m)
{ m.to_json(j); }

}
