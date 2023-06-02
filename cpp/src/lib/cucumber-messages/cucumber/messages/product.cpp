#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/product.hpp>

namespace cucumber::messages {

std::string
product::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "name=", name);
    cucumber::messages::to_string(oss, ", version=", version);

    return oss.str();
}

void
product::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("name"), name);
    cucumber::messages::to_json(j, camelize("version"), version);
}

std::string
product::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const product& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const product& m)
{ m.to_json(j); }

}
