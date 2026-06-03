#pragma once

#include <string_view>

namespace cucumber::messages {

enum class test_step_result_status
{
    UNKNOWN,
    PASSED,
    SKIPPED,
    PENDING,
    UNDEFINED,
    AMBIGUOUS,
    FAILED
};

std::string_view
to_string(test_step_result_status v);

std::ostream&
operator<<(std::ostream& os, test_step_result_status v);

}
