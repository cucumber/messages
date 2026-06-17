#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/snippet.hpp>

namespace cucumber::messages {

std::string
snippet::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "language=", language);
    cucumber::messages::to_string(oss, ", code=", code);

    return oss.str();
}

void
snippet::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("language"), language);
    cucumber::messages::to_json(j, camelize("code"), code);
}

std::string
snippet::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const snippet& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const snippet& m)
{ m.to_json(j); }

}
