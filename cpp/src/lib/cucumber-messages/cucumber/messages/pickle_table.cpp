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

std::ostream&
operator<<(std::ostream& os, const pickle_table& msg)
{
    os << msg.to_string();

    return os;
}

}
