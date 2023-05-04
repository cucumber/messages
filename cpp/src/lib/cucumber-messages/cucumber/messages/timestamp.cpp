#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/timestamp.hpp>

namespace cucumber::messages {

std::string
timestamp::to_string() const
{
    std::ostringstream oss;

    oss
        << "seconds=" << seconds
        << ", nanos=" << nanos
        ;

    return oss.str();
}

}
