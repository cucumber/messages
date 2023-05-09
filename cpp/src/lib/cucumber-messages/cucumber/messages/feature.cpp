#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/feature.hpp>

namespace cucumber::messages {

std::string
feature::to_string() const
{
    std::ostringstream oss;

    oss
    << "location=" << location
    << ", tags=" << tags
    << ", language=" << language
    << ", keyword=" << keyword
    << ", name=" << name
    << ", description=" << description
    << ", children=" << children
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const feature& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const feature& m)
{
    j = json{
        { "location", m.location },
        { "tags", m.tags },
        { "language", m.language },
        { "keyword", m.keyword },
        { "name", m.name },
        { "description", m.description },
        { "children", m.children }
    };
}

}
