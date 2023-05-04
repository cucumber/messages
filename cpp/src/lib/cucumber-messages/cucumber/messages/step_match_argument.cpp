#include <sstream>

#include <cucumber/utils.hpp>
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

}
