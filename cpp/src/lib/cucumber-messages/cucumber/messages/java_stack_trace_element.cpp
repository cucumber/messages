#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/java_stack_trace_element.hpp>

namespace cucumber::messages {

std::string
java_stack_trace_element::to_string() const
{
    std::ostringstream oss;

    oss
        << "class_name=" << class_name
        << ", file_name=" << file_name
        << ", method_name=" << method_name
        ;

    return oss.str();
}

}
