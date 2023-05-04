#include <sstream>

#include <cucumber/utils.hpp>
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

}
