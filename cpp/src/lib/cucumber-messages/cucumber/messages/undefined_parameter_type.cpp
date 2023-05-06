#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/undefined_parameter_type.hpp>

namespace cucumber::messages {

std::string
undefined_parameter_type::to_string() const
{
    std::ostringstream oss;

    oss
    << "expression=" << expression
    << ", name=" << name
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const undefined_parameter_type& msg)
{
    os << msg.to_string();

    return os;
}

}
