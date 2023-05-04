#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/hook.hpp>

namespace cucumber::messages {

std::string
hook::to_string() const
{
    std::ostringstream oss;

    oss
        << "id=" << id
        << ", name=" << name
        << ", source_reference=" << source_reference
        << ", tag_expression=" << tag_expression
        ;

    return oss.str();
}

}
