#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/test_run_finished.hpp>

namespace cucumber::messages {

std::string
test_run_finished::to_string() const
{
    std::ostringstream oss;

    oss
    << "message=" << message
    << ", success=" << success
    << ", timestamp=" << timestamp
    << ", exception=" << exception
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const test_run_finished& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const test_run_finished& m)
{
    j = json{
        { "message", m.message },
        { "success", m.success },
        { "timestamp", m.timestamp },
        { "exception", m.exception }
    };
}

}
