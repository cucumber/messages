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

std::ostream&
operator<<(std::ostream& os, const examples& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const examples& m)
{
    j = json{
        { "location", m.location },
        { "tags", m.tags },
        { "keyword", m.keyword },
        { "name", m.name },
        { "description", m.description },
        { "table_header", m.table_header },
        { "table_body", m.table_body },
        { "id", m.id }
    };
}

}
