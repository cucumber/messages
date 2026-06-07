#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/gherkin_document.hpp>

namespace cucumber::messages {

std::string
gherkin_document::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "uri=", uri);
    cucumber::messages::to_string(oss, ", feature=", feature);
    cucumber::messages::to_string(oss, ", comments=", comments);

    return oss.str();
}

void
gherkin_document::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("uri"), uri);
    cucumber::messages::to_json(j, camelize("feature"), feature);
    cucumber::messages::to_json(j, camelize("comments"), comments);
}

std::string
gherkin_document::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const gherkin_document& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const gherkin_document& m)
{ m.to_json(j); }

}
