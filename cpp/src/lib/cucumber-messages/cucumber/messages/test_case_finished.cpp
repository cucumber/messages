#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/test_case_finished.hpp>

namespace cucumber::messages {

std::string
test_case_finished::to_string() const
{
    std::ostringstream oss;

    oss
    << "test_case_started_id=" << test_case_started_id
    << ", timestamp=" << timestamp
    << ", will_be_retried=" << will_be_retried
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const test_case_finished& msg)
{
    os << msg.to_string();

    return os;
}

}
