#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/doc_string.hpp>

namespace cucumber::messages {

std::string
doc_string::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "location=", location);
    cucumber::messages::to_string(oss, ", media_type=", media_type);
    cucumber::messages::to_string(oss, ", content=", content);
    cucumber::messages::to_string(oss, ", delimiter=", delimiter);

    return oss.str();
}

void
doc_string::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("location"), location);
    cucumber::messages::to_json(j, camelize("media_type"), media_type);
    cucumber::messages::to_json(j, camelize("content"), content);
    cucumber::messages::to_json(j, camelize("delimiter"), delimiter);
}

std::string
doc_string::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const doc_string& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const doc_string& m)
{ m.to_json(j); }

}
