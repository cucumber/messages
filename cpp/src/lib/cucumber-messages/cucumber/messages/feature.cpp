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

void
feature::to_json(json& j) const
{
    j[camelize("feature")] = json{
        { camelize("location"), location },
        { camelize("tags"), tags },
        { camelize("language"), language },
        { camelize("keyword"), keyword },
        { camelize("name"), name },
        { camelize("description"), description },
        { camelize("children"), children }
    };
}

std::string
feature::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const feature& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const feature& m)
{ m.to_json(j); }

}
