#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/rule.hpp>

namespace cucumber::messages {

std::string
rule::to_string() const
{
    std::ostringstream oss;

    oss
        << "location=" << location
        << ", tags=" << tags
        << ", keyword=" << keyword
        << ", name=" << name
        << ", description=" << description
        << ", children=" << children
        << ", id=" << id
        ;

    return oss.str();
}

void
rule::to_json(json& j) const
{
    j = json{
        { camelize("location"), location },
        { camelize("tags"), tags },
        { camelize("keyword"), keyword },
        { camelize("name"), name },
        { camelize("description"), description },
        { camelize("children"), children },
        { camelize("id"), id }
    };
}

std::string
rule::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const rule& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const rule& m)
{ m.to_json(j); }

}
