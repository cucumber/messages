#include <sstream>

#include <cucumber/utils.hpp>
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

}
