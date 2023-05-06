#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/gherkin_document.hpp>

namespace cucumber::messages {

std::string
gherkin_document::to_string() const
{
    std::ostringstream oss;

    oss
    << "uri=" << uri
    << ", feature=" << feature
    << ", comments=" << comments
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const gherkin_document& msg)
{
    os << msg.to_string();

    return os;
}

}
