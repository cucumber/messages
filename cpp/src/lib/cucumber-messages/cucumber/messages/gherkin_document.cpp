#include <sstream>

#include <cucumber/utils.hpp>
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

}
