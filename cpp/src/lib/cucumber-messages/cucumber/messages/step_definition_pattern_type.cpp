#include <unordered_map>

#include <cucumber/messages/step_definition_pattern_type.hpp>

namespace cucumber::messages {

std::string_view
to_string(step_definition_pattern_type v)
{
    using map_type = std::unordered_map<step_definition_pattern_type, std::string_view>;

    static const map_type m = {
        { step_definition_pattern_type::CUCUMBER_EXPRESSION, "CUCUMBER_EXPRESSION" },
        { step_definition_pattern_type::REGULAR_EXPRESSION, "REGULAR_EXPRESSION" }
    };

    return m.at(v);
}

std::ostream&
operator<<(std::ostream& os, step_definition_pattern_type v)
{
    os << to_string(v);

    return os;
}

}
