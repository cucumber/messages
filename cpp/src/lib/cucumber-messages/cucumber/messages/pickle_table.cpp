#include <sstream>

#include <cucumber/utils.hpp>
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

}
