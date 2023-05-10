#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/pickle_table.hpp>

namespace cucumber::messages {

std::string
pickle_table::to_string() const
{
    std::ostringstream oss;

    oss
    << "rows=" << rows
        ;

    return oss.str();
}

void
pickle_table::to_json(json& j) const
{
    j = json{
        { "rows", rows }
    };
}

std::string
pickle_table::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const pickle_table& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const pickle_table& m)
{ m.to_json(j); }

}
