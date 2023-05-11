#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/examples.hpp>

namespace cucumber::messages {

std::string
examples::to_string() const
{
    std::ostringstream oss;

    oss
        << "location=" << location
        << ", tags=" << tags
        << ", keyword=" << keyword
        << ", name=" << name
        << ", description=" << description
        << ", table_header=" << table_header
        << ", table_body=" << table_body
        << ", id=" << id
        ;

    return oss.str();
}

void
examples::to_json(json& j) const
{
    j = json{
        { camelize("location"), location },
        { camelize("tags"), tags },
        { camelize("keyword"), keyword },
        { camelize("name"), name },
        { camelize("description"), description },
        { camelize("table_header"), table_header },
        { camelize("table_body"), table_body },
        { camelize("id"), id }
    };
}

std::string
examples::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const examples& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const examples& m)
{ m.to_json(j); }

}
