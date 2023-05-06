#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/ci.hpp>

namespace cucumber::messages {

std::string
ci::to_string() const
{
    std::ostringstream oss;

    oss
    << "name=" << name
    << ", url=" << url
    << ", build_number=" << build_number
    << ", git=" << git
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const ci& msg)
{
    os << msg.to_string();

    return os;
}

}
