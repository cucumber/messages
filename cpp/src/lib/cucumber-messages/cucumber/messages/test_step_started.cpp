#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/test_step_started.hpp>

namespace cucumber::messages {

std::string
test_step_started::to_string() const
{
    std::ostringstream oss;

    oss
        << "test_case_started_id=" << test_case_started_id
        << ", test_step_id=" << test_step_id
        << ", timestamp=" << timestamp
        ;

    return oss.str();
}

}
