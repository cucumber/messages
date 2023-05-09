#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/pickle_table_cell.hpp>

namespace cucumber::messages {

std::string
pickle_table_cell::to_string() const
{
    std::ostringstream oss;

    oss
    << "value=" << value
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const pickle_table_cell& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const pickle_table_cell& m)
{
    j = json{
        { "value", m.value }
    };
}

}
