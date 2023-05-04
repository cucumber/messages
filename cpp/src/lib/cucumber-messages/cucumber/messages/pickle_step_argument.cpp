#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/pickle_step_argument.hpp>

namespace cucumber::messages {

std::string
pickle_step_argument::to_string() const
{
    std::ostringstream oss;

    oss
        << "doc_string=" << doc_string
        << ", data_table=" << data_table
        ;

    return oss.str();
}

}
