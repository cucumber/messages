#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/group.hpp>

namespace cucumber::messages {

std::string
group::to_string() const
{
    std::ostringstream oss;

    oss
        << "children=" << children
        << ", start=" << start
        << ", value=" << value
        ;

    return oss.str();
}

void
group::to_json(json& j) const
{
    j = json{
        { camelize("children"), children },
        { camelize("start"), start },
        { camelize("value"), value }
    };
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
