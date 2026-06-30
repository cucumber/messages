
#include "cucumber/messages/test_step_result.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string test_step_result::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "duration=", duration);
        cucumber::messages::to_string(oss, ", message=", message);
        cucumber::messages::to_string(oss, ", status=", status);
        cucumber::messages::to_string(oss, ", exception=", exception);

        return oss.str();
    }

    void test_step_result::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("duration"), duration);
        cucumber::messages::to_json(json, camelize("message"), message);
        cucumber::messages::to_json(json, camelize("status"), status);
        cucumber::messages::to_json(json, camelize("exception"), exception);
    }

    void test_step_result::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("duration"), duration);
        cucumber::messages::from_json(json, camelize("message"), message);
        cucumber::messages::from_json(json, camelize("status"), status);
        cucumber::messages::from_json(json, camelize("exception"), exception);
    }

    std::string test_step_result::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const test_step_result& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const test_step_result& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, test_step_result& msg)
    {
        msg.from_json(json);
    }
}
