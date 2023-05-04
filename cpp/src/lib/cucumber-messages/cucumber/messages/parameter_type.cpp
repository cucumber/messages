#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/parameter_type.hpp>

namespace cucumber::messages {

std::string
parameter_type::to_string() const
{
    std::ostringstream oss;

    oss
        << "name=" << name
        << ", regular_expressions=" << cucumber::to_string(regular_expressions)
        << ", prefer_for_regular_expression_match=" << prefer_for_regular_expression_match
        << ", use_for_snippets=" << use_for_snippets
        << ", id=" << id
        << ", source_reference=" << source_reference
        ;

    return oss.str();
}

}
