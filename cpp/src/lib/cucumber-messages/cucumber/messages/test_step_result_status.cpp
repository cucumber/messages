#include <unordered_map>

#include <cucumber/messages/test_step_result_status.hpp>

namespace cucumber::messages {

std::string_view
to_string(test_step_result_status v)
{
    using map_type = std::unordered_map<test_step_result_status, std::string_view>;

    static const map_type m = {
        { test_step_result_status::UNKNOWN, "UNKNOWN" },
        { test_step_result_status::PASSED, "PASSED" },
        { test_step_result_status::SKIPPED, "SKIPPED" },
        { test_step_result_status::PENDING, "PENDING" },
        { test_step_result_status::UNDEFINED, "UNDEFINED" },
        { test_step_result_status::AMBIGUOUS, "AMBIGUOUS" },
        { test_step_result_status::FAILED, "FAILED" }
    };

    return m.at(v);
}

std::ostream&
operator<<(std::ostream& os, test_step_result_status v)
{
    os << to_string(v);

    return os;
}

}