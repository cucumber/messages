
#include "cucumber/messages/test_case.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
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
        json[camelize("id")] = id;
        json[camelize("pickle_id")] = pickle_id;
        json[camelize("test_steps")] = test_steps;
        if (test_run_started_id.has_value())
        {
            json[camelize("test_run_started_id")] = test_run_started_id;
        }
    }

    void test_case::from_json(const nlohmann::json& json)
    {
        json.at(camelize("id")).get_to(id);
        json.at(camelize("pickle_id")).get_to(pickle_id);
        json.at(camelize("test_steps")).get_to(test_steps);
        if (test_run_started_id.has_value())
        {
            json.at(camelize("test_run_started_id")).get_to(test_run_started_id.emplace());
        }
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

    void from_json(const nlohmann::json& json, std::shared_ptr<test_case>& msg)
    {
        msg = std::make_shared<test_case>();
        msg->from_json(json);
    }
}
