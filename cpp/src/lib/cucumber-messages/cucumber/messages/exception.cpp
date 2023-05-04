#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/exception.hpp>

namespace cucumber::messages {

std::string
exception::to_string() const
{
    std::ostringstream oss;

    oss
        << "type=" << type
        << ", message=" << message
        ;

    return oss.str();
}

}
