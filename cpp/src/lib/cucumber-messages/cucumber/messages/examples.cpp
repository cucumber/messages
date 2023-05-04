#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/examples.hpp>

namespace cucumber::messages {

std::string
examples::to_string() const
{
    std::ostringstream oss;

    oss
        << "location=" << location
        << ", tags=" << tags
        << ", keyword=" << keyword
        << ", name=" << name
        << ", description=" << description
        << ", table_header=" << table_header
        << ", table_body=" << table_body
        << ", id=" << id
        ;

    return oss.str();
}

}
