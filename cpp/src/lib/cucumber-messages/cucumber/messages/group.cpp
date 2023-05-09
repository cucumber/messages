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

std::ostream&
operator<<(std::ostream& os, const group& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const group& m)
{
    j = json{
        { "children", m.children },
        { "start", m.start },
        { "value", m.value }
    };
}

}
