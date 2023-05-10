#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/doc_string.hpp>

namespace cucumber::messages {

std::string
doc_string::to_string() const
{
    std::ostringstream oss;

    oss
    << "location=" << location
    << ", media_type=" << media_type
    << ", content=" << content
    << ", delimiter=" << delimiter
        ;

    return oss.str();
}

void
doc_string::to_json(json& j) const
{
    j[camelize("doc_string")] = json{
        { camelize("location"), location },
        { camelize("media_type"), media_type },
        { camelize("content"), content },
        { camelize("delimiter"), delimiter }
    };
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
