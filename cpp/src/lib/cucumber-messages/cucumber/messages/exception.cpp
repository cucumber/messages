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

void
exception::to_json(json& j) const
{
    j[camelize("exception")] = json{
        { camelize("type"), type },
        { camelize("message"), message }
    };
}

std::string
exception::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const exception& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const exception& m)
{ m.to_json(j); }

}
