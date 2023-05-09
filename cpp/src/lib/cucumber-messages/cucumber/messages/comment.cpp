#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/comment.hpp>

namespace cucumber::messages {

std::string
comment::to_string() const
{
    std::ostringstream oss;

    oss
    << "location=" << location
    << ", text=" << text
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const comment& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const comment& m)
{
    j = json{
        { "location", m.location },
        { "text", m.text }
    };
}

}
