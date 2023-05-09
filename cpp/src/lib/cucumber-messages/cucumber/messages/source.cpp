#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/source.hpp>

namespace cucumber::messages {

std::string
source::to_string() const
{
    std::ostringstream oss;

    oss
    << "uri=" << uri
    << ", data=" << data
    << ", media_type=" << media_type
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const source& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const source& m)
{
    j = json{
        { "uri", m.uri },
        { "data", m.data },
        { "media_type", m.media_type }
    };
}

}
