#include <sstream>

#include <cucumber/messages/utils.hpp>
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

void
java_stack_trace_element::to_json(json& j) const
{
    j[camelize("java_stack_trace_element")] = json{
        { camelize("class_name"), class_name },
        { camelize("file_name"), file_name },
        { camelize("method_name"), method_name }
    };
}

std::string
java_stack_trace_element::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const java_stack_trace_element& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const java_stack_trace_element& m)
{ m.to_json(j); }

}
