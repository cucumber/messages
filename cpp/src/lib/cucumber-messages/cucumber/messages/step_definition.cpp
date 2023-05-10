#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/step_definition.hpp>

namespace cucumber::messages {

std::string
step_definition::to_string() const
{
    std::ostringstream oss;

    oss
    << "id=" << id
    << ", pattern=" << pattern
    << ", source_reference=" << source_reference
        ;

    return oss.str();
}

void
step_definition::to_json(json& j) const
{
    j[camelize("step_definition")] = json{
        { camelize("id"), id },
        { camelize("pattern"), pattern },
        { camelize("source_reference"), source_reference }
    };
}

std::string
step_definition::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const step_definition& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const step_definition& m)
{ m.to_json(j); }

}
