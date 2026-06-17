#pragma once

#include <string_view>

namespace cucumber::messages {

enum class hook_type
{
    BEFORE_TEST_RUN,
    AFTER_TEST_RUN,
    BEFORE_TEST_CASE,
    AFTER_TEST_CASE,
    BEFORE_TEST_STEP,
    AFTER_TEST_STEP
};

std::string_view
to_string(hook_type v);

std::ostream&
operator<<(std::ostream& os, hook_type v);

}
