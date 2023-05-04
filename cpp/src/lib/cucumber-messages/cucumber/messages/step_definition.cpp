#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/step_definition.hpp>

namespace cucumber::messages {

std::string
step_definition::to_string() const
{
    std::ostringstream oss;

    oss
        << "id=" << id
        << ", pattern=" << pattern
        << ", source_reference=" << source_reference
        ;

    return oss.str();
}

}
