#include <sstream>

#include <cucumber/utils.hpp>
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

}
