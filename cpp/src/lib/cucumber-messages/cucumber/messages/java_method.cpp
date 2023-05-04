#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/java_method.hpp>

namespace cucumber::messages {

std::string
java_method::to_string() const
{
    std::ostringstream oss;

    oss
        << "class_name=" << class_name
        << ", method_name=" << method_name
        << ", method_parameter_types=" << cucumber::to_string(method_parameter_types)
        ;

    return oss.str();
}

}
