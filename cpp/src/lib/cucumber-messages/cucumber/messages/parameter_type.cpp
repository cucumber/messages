#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/parameter_type.hpp>

namespace cucumber::messages {

std::string
parameter_type::to_string() const
{
    std::ostringstream oss;

    oss
    << "name=" << name
    << ", regular_expressions=" << regular_expressions
    << ", prefer_for_regular_expression_match=" << prefer_for_regular_expression_match
    << ", use_for_snippets=" << use_for_snippets
    << ", id=" << id
    << ", source_reference=" << source_reference
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const parameter_type& msg)
{
    os << msg.to_string();

    return os;
}

}
