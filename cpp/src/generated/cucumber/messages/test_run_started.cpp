
#include "cucumber/messages/test_run_started.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string test_run_started::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "timestamp=", timestamp);
        cucumber::messages::to_string(oss, ", id=", id);

        return oss.str();
    }

    void test_run_started::to_json(nlohmann::json& json) const
    {
        json[camelize("timestamp")] = timestamp;
        if (id.has_value())
        {
            json[camelize("id")] = id;
        }
    }

    void test_run_started::from_json(const nlohmann::json& json)
    {
        json.at(camelize("timestamp")).get_to(timestamp);
        if (id.has_value())
        {
            json.at(camelize("id")).get_to(id.emplace());
        }
    }

    std::string test_run_started::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const test_run_started& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const test_run_started& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, test_run_started& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<test_run_started>& msg)
    {
        msg = std::make_shared<test_run_started>();
        msg->from_json(json);
    }
}
