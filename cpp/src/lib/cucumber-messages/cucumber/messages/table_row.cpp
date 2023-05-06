#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/table_row.hpp>

namespace cucumber::messages {

std::string
table_row::to_string() const
{
    std::ostringstream oss;

    oss
    << "location=" << location
    << ", cells=" << cells
    << ", id=" << id
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const table_row& msg)
{
    os << msg.to_string();

    return os;
}

}
