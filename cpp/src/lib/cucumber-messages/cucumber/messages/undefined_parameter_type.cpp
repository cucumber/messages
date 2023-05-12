#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/undefined_parameter_type.hpp>

namespace cucumber::messages {

std::string
undefined_parameter_type::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "expression=", expression);
    cucumber::messages::to_string(oss, ", name=", name);

    return oss.str();
}

void
undefined_parameter_type::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("expression"), expression);
    cucumber::messages::to_json(j, camelize("name"), name);
}

std::string
undefined_parameter_type::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const undefined_parameter_type& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const undefined_parameter_type& m)
{ m.to_json(j); }

}
