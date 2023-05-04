#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/test_step_result.hpp>

namespace cucumber::messages {

std::string
test_step_result::to_string() const
{
    std::ostringstream oss;

    oss
        << "duration=" << duration
        << ", message=" << message
        << ", status=" << status
        << ", exception=" << exception
        ;

    return oss.str();
}

}
