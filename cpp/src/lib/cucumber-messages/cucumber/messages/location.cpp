#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/location.hpp>

namespace cucumber::messages {

std::string
location::to_string() const
{
    std::ostringstream oss;

    oss
    << "line=" << line
    << ", column=" << column
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const location& msg)
{
    os << msg.to_string();

    return os;
}

}
