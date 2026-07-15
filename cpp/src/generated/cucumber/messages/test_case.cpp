
#include "cucumber/messages/test_case.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string test_case::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "id=", id);
        cucumber::messages::to_string(oss, ", pickle_id=", pickle_id);
        cucumber::messages::to_string(oss, ", test_steps=", test_steps);
        cucumber::messages::to_string(oss, ", test_run_started_id=", test_run_started_id);

        return oss.str();
    }

    void test_case::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("id"), id);
        cucumber::messages::to_json(json, camelize("pickle_id"), pickle_id);
        cucumber::messages::to_json(json, camelize("test_steps"), test_steps);
        cucumber::messages::to_json(json, camelize("test_run_started_id"), test_run_started_id);
    }

    void test_case::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("id"), id);
        cucumber::messages::from_json(json, camelize("pickle_id"), pickle_id);
        cucumber::messages::from_json(json, camelize("test_steps"), test_steps);
        cucumber::messages::from_json(json, camelize("test_run_started_id"), test_run_started_id);
    }

    std::string test_case::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const test_case& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const test_case& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, test_case& msg)
    {
        msg.from_json(json);
    }
}
