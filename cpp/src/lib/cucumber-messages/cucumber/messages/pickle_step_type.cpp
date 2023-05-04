#include <unordered_map>

#include <cucumber/messages/pickle_step_type.hpp>

namespace cucumber::messages {

std::string_view
to_string(pickle_step_type v)
{
    using map_type = std::unordered_map<pickle_step_type, std::string_view>;

    static const map_type m = {
        { UNKNOWN, "Unknown" },
        { CONTEXT, "Context" },
        { ACTION, "Action" },
        { OUTCOME, "Outcome" }
    };

    return m.at(v);
}

std::ostream&
operator<<(std::ostream& os, pickle_step_type v)
{
    os << to_string(v);

    return os;
}

}
