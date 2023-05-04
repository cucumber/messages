#include <sstream>

#include <cucumber/utils.hpp>
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

}
