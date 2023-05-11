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

void
table_cell::to_json(json& j) const
{
    j = json{
        { camelize("location"), location },
        { camelize("value"), value }
    };
}

std::string
table_cell::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const table_cell& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const table_cell& m)
{ m.to_json(j); }

}
