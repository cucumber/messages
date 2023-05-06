#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/rule.hpp>

namespace cucumber::messages {

std::string
rule::to_string() const
{
    std::ostringstream oss;

    oss
    << "location=" << location
    << ", tags=" << tags
    << ", keyword=" << keyword
    << ", name=" << name
    << ", description=" << description
    << ", children=" << children
    << ", id=" << id
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const rule& msg)
{
    os << msg.to_string();

    return os;
}

}
