#include <iostream>
#include <unordered_map>

#include <cucumber/messages/hook_type.hpp>

namespace cucumber::messages {

std::string_view
to_string(hook_type v)
{
    using map_type = std::unordered_map<hook_type, std::string_view>;

    static const map_type m = {
        { hook_type::BEFORE, "BEFORE" },
        { hook_type::AFTER, "AFTER" },
        { hook_type::BEFORE_STEP, "BEFORE_STEP" },
        { hook_type::AFTER_STEP, "AFTER_STEP" }
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
