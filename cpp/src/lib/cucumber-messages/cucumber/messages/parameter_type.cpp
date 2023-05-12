#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/parameter_type.hpp>

namespace cucumber::messages {

std::string
parameter_type::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "name=", name);
    cucumber::messages::to_string(oss, ", regular_expressions=", regular_expressions);
    cucumber::messages::to_string(oss, ", prefer_for_regular_expression_match=", prefer_for_regular_expression_match);
    cucumber::messages::to_string(oss, ", use_for_snippets=", use_for_snippets);
    cucumber::messages::to_string(oss, ", id=", id);
    cucumber::messages::to_string(oss, ", source_reference=", source_reference);

    return oss.str();
}

void
parameter_type::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("name"), name);
    cucumber::messages::to_json(j, camelize("regular_expressions"), regular_expressions);
    cucumber::messages::to_json(j, camelize("prefer_for_regular_expression_match"), prefer_for_regular_expression_match);
    cucumber::messages::to_json(j, camelize("use_for_snippets"), use_for_snippets);
    cucumber::messages::to_json(j, camelize("id"), id);
    cucumber::messages::to_json(j, camelize("source_reference"), source_reference);
}

std::string
parameter_type::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const parameter_type& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const parameter_type& m)
{ m.to_json(j); }

}
