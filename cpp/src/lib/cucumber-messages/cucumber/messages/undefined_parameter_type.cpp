#include <sstream>

#include <cucumber/utils.hpp>
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

}
