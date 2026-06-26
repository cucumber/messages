
#include "cucumber/messages/test_step.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string test_step::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "hook_id=", hook_id);
        cucumber::messages::to_string(oss, ", id=", id);
        cucumber::messages::to_string(oss, ", pickle_step_id=", pickle_step_id);
        cucumber::messages::to_string(oss, ", step_definition_ids=", step_definition_ids);
        cucumber::messages::to_string(oss, ", step_match_arguments_lists=", step_match_arguments_lists);

        return oss.str();
    }

    void test_step::to_json(nlohmann::json& json) const
    {
        if (hook_id.has_value())
        {
            json[camelize("hook_id")] = hook_id;
        }
        json[camelize("id")] = id;
        if (pickle_step_id.has_value())
        {
            json[camelize("pickle_step_id")] = pickle_step_id;
        }
        if (step_definition_ids.has_value())
        {
            json[camelize("step_definition_ids")] = step_definition_ids;
        }
        if (step_match_arguments_lists.has_value())
        {
            json[camelize("step_match_arguments_lists")] = step_match_arguments_lists;
        }
    }

    void test_step::from_json(const nlohmann::json& json)
    {
        if (hook_id.has_value())
        {
            json.at(camelize("hook_id")).get_to(hook_id.emplace());
        }
        json.at(camelize("id")).get_to(id);
        if (pickle_step_id.has_value())
        {
            json.at(camelize("pickle_step_id")).get_to(pickle_step_id.emplace());
        }
        if (step_definition_ids.has_value())
        {
            json.at(camelize("step_definition_ids")).get_to(step_definition_ids.emplace());
        }
        if (step_match_arguments_lists.has_value())
        {
            json.at(camelize("step_match_arguments_lists")).get_to(step_match_arguments_lists.emplace());
        }
    }

    std::string test_step::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const test_step& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const test_step& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, test_step& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<test_step>& msg)
    {
        msg = std::make_shared<test_step>();
        msg->from_json(json);
    }
}
