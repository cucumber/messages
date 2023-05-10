#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/scenario.hpp>

namespace cucumber::messages {

std::string
scenario::to_string() const
{
    std::ostringstream oss;

    oss
    << "location=" << location
    << ", tags=" << tags
    << ", keyword=" << keyword
    << ", name=" << name
    << ", description=" << description
    << ", steps=" << steps
    << ", examples=" << examples
    << ", id=" << id
        ;

    return oss.str();
}

void
scenario::to_json(json& j) const
{
    j[camelize("scenario")] = json{
        { camelize("location"), location },
        { camelize("tags"), tags },
        { camelize("keyword"), keyword },
        { camelize("name"), name },
        { camelize("description"), description },
        { camelize("steps"), steps },
        { camelize("examples"), examples },
        { camelize("id"), id }
    };
}

std::string
scenario::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const scenario& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const scenario& m)
{ m.to_json(j); }

}
