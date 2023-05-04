#include <unordered_map>

#include <cucumber/messages/step_keyword_type.hpp>

namespace cucumber::messages {

std::string_view
to_string(step_keyword_type v)
{
    using map_type = std::unordered_map<step_keyword_type, std::string_view>;

    static const map_type m = {
        { UNKNOWN, "Unknown" },
        { CONTEXT, "Context" },
        { ACTION, "Action" },
        { OUTCOME, "Outcome" },
        { CONJUNCTION, "Conjunction" }
    };

    return m.at(v);
}

std::ostream&
operator<<(std::ostream& os, step_keyword_type v)
{
    os << to_string(v);

    return os;
}

}
