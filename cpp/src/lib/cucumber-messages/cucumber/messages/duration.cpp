#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/duration.hpp>

namespace cucumber::messages {

std::string
duration::to_string() const
{
    std::ostringstream oss;

    oss
        << "seconds=" << seconds
        << ", nanos=" << nanos
        ;

    return oss.str();
}

}
