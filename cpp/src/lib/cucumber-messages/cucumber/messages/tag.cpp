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

std::ostream&
operator<<(std::ostream& os, const tag& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const tag& m)
{
    j = json{
        { "location", m.location },
        { "name", m.name },
        { "id", m.id }
    };
}

}
