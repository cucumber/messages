#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/test_run_started.hpp>

namespace cucumber::messages {

std::string
test_run_started::to_string() const
{
    std::ostringstream oss;

    oss
        << "timestamp=" << timestamp
        ;

    return oss.str();
}

}
