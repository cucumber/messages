#include <sstream>

#include <cucumber/messages/utils.hpp>
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

void
hook::to_json(json& j) const
{
    j[camelize("hook")] = json{
        { camelize("id"), id },
        { camelize("name"), name },
        { camelize("source_reference"), source_reference },
        { camelize("tag_expression"), tag_expression }
    };
}

std::string
hook::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const hook& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const hook& m)
{ m.to_json(j); }

}
