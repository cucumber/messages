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

std::ostream&
operator<<(std::ostream& os, const step_definition_pattern& msg)
{
    os << msg.to_string();

    return os;
}

}
