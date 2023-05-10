#include <sstream>

#include <cucumber/messages/utils.hpp>
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

void
pickle_step_argument::to_json(json& j) const
{
    j[camelize("pickle_step_argument")] = json{
        { camelize("doc_string"), doc_string },
        { camelize("data_table"), data_table }
    };
}

std::string
pickle_step_argument::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const pickle_step_argument& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const pickle_step_argument& m)
{ m.to_json(j); }

}
