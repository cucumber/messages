#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/step_match_argument.hpp>

namespace cucumber::messages {

std::string
step_match_argument::to_string() const
{
    std::ostringstream oss;

    oss
    << "group=" << group
    << ", parameter_type_name=" << parameter_type_name
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const step_match_argument& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const step_match_argument& m)
{
    j = json{
        { "group", m.group },
        { "parameter_type_name", m.parameter_type_name }
    };
}

}
