#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/table_cell.hpp>

namespace cucumber::messages {

std::string
table_cell::to_string() const
{
    std::ostringstream oss;

    oss
    << "location=" << location
    << ", value=" << value
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const table_cell& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const table_cell& m)
{
    j = json{
        { "location", m.location },
        { "value", m.value }
    };
}

}
