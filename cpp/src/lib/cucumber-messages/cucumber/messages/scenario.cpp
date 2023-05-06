#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/scenario.hpp>

namespace cucumber::messages {

std::string
scenario::to_string() const
{
    std::ostringstream oss;

    oss
    << "location=" << location
    << ", tags=" << tags
    << ", keyword=" << keyword
    << ", name=" << name
    << ", description=" << description
    << ", steps=" << steps
    << ", examples=" << examples
    << ", id=" << id
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const scenario& msg)
{
    os << msg.to_string();

    return os;
}

}
