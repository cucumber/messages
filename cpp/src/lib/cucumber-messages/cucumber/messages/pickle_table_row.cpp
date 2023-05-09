#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/pickle_table_row.hpp>

namespace cucumber::messages {

std::string
pickle_table_row::to_string() const
{
    std::ostringstream oss;

    oss
    << "cells=" << cells
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const pickle_table_row& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const pickle_table_row& m)
{
    j = json{
        { "cells", m.cells }
    };
}

}
