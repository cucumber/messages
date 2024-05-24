#pragma once

#include <string_view>

namespace cucumber::messages {

enum class hook_type
{
    BEFORE,
    AFTER,
    BEFORE_STEP,
    AFTER_STEP
};

std::string_view
to_string(hook_type v);

std::ostream&
operator<<(std::ostream& os, hook_type v);

}
