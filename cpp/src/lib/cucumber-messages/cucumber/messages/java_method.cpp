#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/java_method.hpp>

namespace cucumber::messages {

std::string
java_method::to_string() const
{
    std::ostringstream oss;

    oss
    << "class_name=" << class_name
    << ", method_name=" << method_name
    << ", method_parameter_types=" << method_parameter_types
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const java_method& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const java_method& m)
{
    j = json{
        { "class_name", m.class_name },
        { "method_name", m.method_name },
        { "method_parameter_types", m.method_parameter_types }
    };
}

}
