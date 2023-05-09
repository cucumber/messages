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

std::ostream&
operator<<(std::ostream& os, const source_reference& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const source_reference& m)
{
    j = json{
        { "uri", m.uri },
        { "java_method", m.java_method },
        { "java_stack_trace_element", m.java_stack_trace_element },
        { "location", m.location }
    };
}

}
