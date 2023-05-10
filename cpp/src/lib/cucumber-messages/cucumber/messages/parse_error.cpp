#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/parse_error.hpp>

namespace cucumber::messages {

std::string
parse_error::to_string() const
{
    std::ostringstream oss;

    oss
    << "source=" << source
    << ", message=" << message
        ;

    return oss.str();
}

void
parse_error::to_json(json& j) const
{
    j[camelize("parse_error")] = json{
        { camelize("source"), source },
        { camelize("message"), message }
    };
}

std::string
parse_error::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const parse_error& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const parse_error& m)
{ m.to_json(j); }

}
