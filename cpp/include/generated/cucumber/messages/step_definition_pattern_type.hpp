#pragma once

#include <string_view>

namespace cucumber::messages {

enum class step_definition_pattern_type
{
    CUCUMBER_EXPRESSION,
    REGULAR_EXPRESSION
};

std::string_view
to_string(step_definition_pattern_type v);

std::ostream&
operator<<(std::ostream& os, step_definition_pattern_type v);

}
