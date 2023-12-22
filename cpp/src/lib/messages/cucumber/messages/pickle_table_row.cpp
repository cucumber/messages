#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/pickle_table_row.hpp>

namespace cucumber::messages {

std::string
pickle_table_row::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "cells=", cells);

    return oss.str();
}

void
pickle_table_row::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("cells"), cells);
}

std::string
pickle_table_row::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const pickle_table_row& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const pickle_table_row& m)
{ m.to_json(j); }

}
