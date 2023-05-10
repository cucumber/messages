#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/data_table.hpp>

namespace cucumber::messages {

std::string
data_table::to_string() const
{
    std::ostringstream oss;

    oss
    << "location=" << location
    << ", rows=" << rows
        ;

    return oss.str();
}

void
data_table::to_json(json& j) const
{
    j[camelize("data_table")] = json{
        { camelize("location"), location },
        { camelize("rows"), rows }
    };
}

std::string
data_table::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const data_table& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const data_table& m)
{ m.to_json(j); }

}
