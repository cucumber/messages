#pragma once

#include <string_view>

namespace cucumber::messages {

enum class pickle_step_type
{
    UNKNOWN,
    CONTEXT,
    ACTION,
    OUTCOME
};

std::string_view
to_string(pickle_step_type v);

std::ostream&
operator<<(std::ostream& os, pickle_step_type v);

}
