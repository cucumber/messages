#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/parse_error.hpp>

namespace cucumber::messages {

std::string
parse_error::to_string() const
{
    std::ostringstream oss;

    oss
        << "source=" << source
        << ", message=" << message
        ;

    return oss.str();
}

}
