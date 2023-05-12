#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/step_match_argument.hpp>

namespace cucumber::messages {

std::string
step_match_argument::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "group=", group);
    cucumber::messages::to_string(oss, ", parameter_type_name=", parameter_type_name);

    return oss.str();
}

void
step_match_argument::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("group"), group);
    cucumber::messages::to_json(j, camelize("parameter_type_name"), parameter_type_name);
}

std::string
step_match_argument::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const step_match_argument& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const step_match_argument& m)
{ m.to_json(j); }

}
