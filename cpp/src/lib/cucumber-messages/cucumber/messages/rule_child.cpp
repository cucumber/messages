#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/rule_child.hpp>

namespace cucumber::messages {

std::string
rule_child::to_string() const
{
    std::ostringstream oss;

    oss
    << "background=" << background
    << ", scenario=" << scenario
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const rule_child& msg)
{
    os << msg.to_string();

    return os;
}

}
