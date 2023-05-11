#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/step.hpp>

namespace cucumber::messages {

std::string
step::to_string() const
{
    std::ostringstream oss;

    oss
        << "location=" << location
        << ", keyword=" << keyword
        << ", keyword_type=" << keyword_type
        << ", text=" << text
        << ", doc_string=" << doc_string
        << ", data_table=" << data_table
        << ", id=" << id
        ;

    return oss.str();
}

void
step::to_json(json& j) const
{
    j = json{
        { camelize("location"), location },
        { camelize("keyword"), keyword },
        { camelize("keyword_type"), keyword_type },
        { camelize("text"), text },
        { camelize("doc_string"), doc_string },
        { camelize("data_table"), data_table },
        { camelize("id"), id }
    };
}

std::string
step::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const step& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const step& m)
{ m.to_json(j); }

}
