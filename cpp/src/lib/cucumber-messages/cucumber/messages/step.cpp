#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/step.hpp>

namespace cucumber::messages {

std::string
step::to_string() const
{
    std::ostringstream oss;

    oss
        << "location=" << location
        << ", keyword=" << keyword
        << ", keyword_type=" << keyword_type
        << ", text=" << text
        << ", doc_string=" << doc_string
        << ", data_table=" << data_table
        << ", id=" << id
        ;

    return oss.str();
}

}
