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

std::ostream&
operator<<(std::ostream& os, const step& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const step& m)
{
    j = json{
        { "location", m.location },
        { "keyword", m.keyword },
        { "keyword_type", m.keyword_type },
        { "text", m.text },
        { "doc_string", m.doc_string },
        { "data_table", m.data_table },
        { "id", m.id }
    };
}

}
