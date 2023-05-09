#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/test_case_started.hpp>

namespace cucumber::messages {

std::string
test_case_started::to_string() const
{
    std::ostringstream oss;

    oss
    << "attempt=" << attempt
    << ", id=" << id
    << ", test_case_id=" << test_case_id
    << ", worker_id=" << worker_id
    << ", timestamp=" << timestamp
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const test_case_started& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const test_case_started& m)
{
    j = json{
        { "attempt", m.attempt },
        { "id", m.id },
        { "test_case_id", m.test_case_id },
        { "worker_id", m.worker_id },
        { "timestamp", m.timestamp }
    };
}

}
