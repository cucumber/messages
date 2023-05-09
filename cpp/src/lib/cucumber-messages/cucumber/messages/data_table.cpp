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

std::ostream&
operator<<(std::ostream& os, const data_table& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const data_table& m)
{
    j = json{
        { "location", m.location },
        { "rows", m.rows }
    };
}

}
