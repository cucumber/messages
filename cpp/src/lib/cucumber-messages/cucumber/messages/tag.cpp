#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/tag.hpp>

namespace cucumber::messages {

std::string
tag::to_string() const
{
    std::ostringstream oss;

    oss
    << "location=" << location
    << ", name=" << name
    << ", id=" << id
        ;

    return oss.str();
}

void
tag::to_json(json& j) const
{
    j[camelize("tag")] = json{
        { camelize("location"), location },
        { camelize("name"), name },
        { camelize("id"), id }
    };
}

std::string
tag::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const tag& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const tag& m)
{ m.to_json(j); }

}
