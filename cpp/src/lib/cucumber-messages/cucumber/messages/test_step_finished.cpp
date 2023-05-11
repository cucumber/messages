#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/test_step_finished.hpp>

namespace cucumber::messages {

std::string
test_step_finished::to_string() const
{
    std::ostringstream oss;

    oss
        << "test_case_started_id=" << test_case_started_id
        << ", test_step_id=" << test_step_id
        << ", test_step_result=" << test_step_result
        << ", timestamp=" << timestamp
        ;

    return oss.str();
}

void
test_step_finished::to_json(json& j) const
{
    j = json{
        { camelize("test_case_started_id"), test_case_started_id },
        { camelize("test_step_id"), test_step_id },
        { camelize("test_step_result"), test_step_result },
        { camelize("timestamp"), timestamp }
    };
}

std::string
test_step_finished::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const test_step_finished& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const test_step_finished& m)
{ m.to_json(j); }

}
