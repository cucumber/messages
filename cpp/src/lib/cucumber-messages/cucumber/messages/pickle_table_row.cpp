#include <sstream>

#include <cucumber/utils.hpp>
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

}
