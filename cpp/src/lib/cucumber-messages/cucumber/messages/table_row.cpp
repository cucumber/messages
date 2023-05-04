#include <sstream>

#include <cucumber/utils.hpp>
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

}
