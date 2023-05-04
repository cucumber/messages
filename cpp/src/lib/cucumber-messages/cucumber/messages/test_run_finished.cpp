#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/test_run_finished.hpp>

namespace cucumber::messages {

std::string
test_run_finished::to_string() const
{
    std::ostringstream oss;

    oss
        << "message=" << message
        << ", success=" << success
        << ", timestamp=" << timestamp
        << ", exception=" << exception
        ;

    return oss.str();
}

}
