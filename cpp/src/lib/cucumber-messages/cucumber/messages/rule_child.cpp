#include <sstream>

#include <cucumber/utils.hpp>
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

}
