#include <sstream>

#include <cucumber/utils.hpp>
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

}
