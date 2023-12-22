#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/step_match_arguments_list.hpp>

namespace cucumber::messages {

std::string
step_match_arguments_list::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "step_match_arguments=", step_match_arguments);

    return oss.str();
}

void
step_match_arguments_list::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("step_match_arguments"), step_match_arguments);
}

std::string
step_match_arguments_list::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const step_match_arguments_list& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const step_match_arguments_list& m)
{ m.to_json(j); }

}
