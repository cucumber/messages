#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/exception.hpp>

namespace cucumber::messages {

std::string
exception::to_string() const
{
    std::ostringstream oss;

    oss
    << "type=" << type
    << ", message=" << message
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const exception& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const exception& m)
{
    j = json{
        { "type", m.type },
        { "message", m.message }
    };
}

}
