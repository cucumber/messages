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

void
background::to_json(json& j) const
{
    j[camelize("background")] = json{
        { camelize("location"), location },
        { camelize("keyword"), keyword },
        { camelize("name"), name },
        { camelize("description"), description },
        { camelize("steps"), steps },
        { camelize("id"), id }
    };
}

std::string
background::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const background& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const background& m)
{ m.to_json(j); }

}
