#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/table_row.hpp>

namespace cucumber::messages {

std::string
table_row::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "location=", location);
    cucumber::messages::to_string(oss, ", cells=", cells);
    cucumber::messages::to_string(oss, ", id=", id);

    return oss.str();
}

void
table_row::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("location"), location);
    cucumber::messages::to_json(j, camelize("cells"), cells);
    cucumber::messages::to_json(j, camelize("id"), id);
}

std::string
table_row::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const table_row& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const table_row& m)
{ m.to_json(j); }

}
