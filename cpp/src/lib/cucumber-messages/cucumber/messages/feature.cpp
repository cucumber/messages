#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/feature.hpp>

namespace cucumber::messages {

std::string
feature::to_string() const
{
    std::ostringstream oss;

    oss
    << "location=" << location
    << ", tags=" << tags
    << ", language=" << language
    << ", keyword=" << keyword
    << ", name=" << name
    << ", description=" << description
    << ", children=" << children
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const feature& msg)
{
    os << msg.to_string();

    return os;
}

}
