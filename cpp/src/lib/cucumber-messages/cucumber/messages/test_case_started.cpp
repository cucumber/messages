#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/test_case_started.hpp>

namespace cucumber::messages {

std::string
test_case_started::to_string() const
{
    std::ostringstream oss;

    oss
        << "attempt=" << attempt
        << ", id=" << id
        << ", test_case_id=" << test_case_id
        << ", worker_id=" << worker_id
        << ", timestamp=" << timestamp
        ;

    return oss.str();
}

}
