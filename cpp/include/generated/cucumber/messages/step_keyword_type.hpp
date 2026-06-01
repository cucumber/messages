#pragma once

#include <string_view>

namespace cucumber::messages {

enum class step_keyword_type
{
    UNKNOWN,
    CONTEXT,
    ACTION,
    OUTCOME,
    CONJUNCTION
};

std::string_view
to_string(step_keyword_type v);

std::ostream&
operator<<(std::ostream& os, step_keyword_type v);

}
