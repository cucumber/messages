#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/group.hpp>

namespace cucumber::messages {

std::string
group::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "children=", children);
    cucumber::messages::to_string(oss, ", start=", start);
    cucumber::messages::to_string(oss, ", value=", value);

    return oss.str();
}

void
group::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("children"), children);
    cucumber::messages::to_json(j, camelize("start"), start);
    cucumber::messages::to_json(j, camelize("value"), value);
}

std::string
group::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const group& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const group& m)
{ m.to_json(j); }

}
