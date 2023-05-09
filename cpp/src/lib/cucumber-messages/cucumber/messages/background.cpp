#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/background.hpp>

namespace cucumber::messages {

std::string
background::to_string() const
{
    std::ostringstream oss;

    oss
    << "location=" << location
    << ", keyword=" << keyword
    << ", name=" << name
    << ", description=" << description
    << ", steps=" << steps
    << ", id=" << id
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const background& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const background& m)
{
    j = json{
        { "location", m.location },
        { "keyword", m.keyword },
        { "name", m.name },
        { "description", m.description },
        { "steps", m.steps },
        { "id", m.id }
    };
}

}
