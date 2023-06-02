#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/step.hpp>

namespace cucumber::messages {

std::string
step::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "location=", location);
    cucumber::messages::to_string(oss, ", keyword=", keyword);
    cucumber::messages::to_string(oss, ", keyword_type=", keyword_type);
    cucumber::messages::to_string(oss, ", text=", text);
    cucumber::messages::to_string(oss, ", doc_string=", doc_string);
    cucumber::messages::to_string(oss, ", data_table=", data_table);
    cucumber::messages::to_string(oss, ", id=", id);

    return oss.str();
}

void
step::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("location"), location);
    cucumber::messages::to_json(j, camelize("keyword"), keyword);
    cucumber::messages::to_json(j, camelize("keyword_type"), keyword_type);
    cucumber::messages::to_json(j, camelize("text"), text);
    cucumber::messages::to_json(j, camelize("doc_string"), doc_string);
    cucumber::messages::to_json(j, camelize("data_table"), data_table);
    cucumber::messages::to_json(j, camelize("id"), id);
}

std::string
step::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const step& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const step& m)
{ m.to_json(j); }

}
