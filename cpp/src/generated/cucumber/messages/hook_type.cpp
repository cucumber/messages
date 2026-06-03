#include <iostream>
#include <unordered_map>

#include <cucumber/messages/hook_type.hpp>

namespace cucumber::messages {

std::string_view
to_string(hook_type v)
{
    using map_type = std::unordered_map<hook_type, std::string_view>;

    static const map_type m = {
        { hook_type::BEFORE_TEST_RUN, "BEFORE_TEST_RUN" },
        { hook_type::AFTER_TEST_RUN, "AFTER_TEST_RUN" },
        { hook_type::BEFORE_TEST_CASE, "BEFORE_TEST_CASE" },
        { hook_type::AFTER_TEST_CASE, "AFTER_TEST_CASE" },
        { hook_type::BEFORE_TEST_STEP, "BEFORE_TEST_STEP" },
        { hook_type::AFTER_TEST_STEP, "AFTER_TEST_STEP" }
    };

    return m.at(v);
}

std::ostream&
operator<<(std::ostream& os, hook_type v)
{
    os << to_string(v);

    return os;
}

}
