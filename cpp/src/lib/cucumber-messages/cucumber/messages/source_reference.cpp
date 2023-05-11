#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/source_reference.hpp>

namespace cucumber::messages {

std::string
source_reference::to_string() const
{
    std::ostringstream oss;

    oss
        << "uri=" << uri
        << ", java_method=" << java_method
        << ", java_stack_trace_element=" << java_stack_trace_element
        << ", location=" << location
        ;

    return oss.str();
}

void
source_reference::to_json(json& j) const
{
    j = json{
        { camelize("uri"), uri },
        { camelize("java_method"), java_method },
        { camelize("java_stack_trace_element"), java_stack_trace_element },
        { camelize("location"), location }
    };
}

std::string
source_reference::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const source_reference& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const source_reference& m)
{ m.to_json(j); }

}
