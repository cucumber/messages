
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
        cucumber::messages::to_json(json, camelize("hook_id"), hook_id);
        cucumber::messages::to_json(json, camelize("id"), id);
        cucumber::messages::to_json(json, camelize("pickle_step_id"), pickle_step_id);
        cucumber::messages::to_json(json, camelize("step_definition_ids"), step_definition_ids);
        cucumber::messages::to_json(json, camelize("step_match_arguments_lists"), step_match_arguments_lists);
    }

    void test_step::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("hook_id"), hook_id);
        cucumber::messages::from_json(json, camelize("id"), id);
        cucumber::messages::from_json(json, camelize("pickle_step_id"), pickle_step_id);
        cucumber::messages::from_json(json, camelize("step_definition_ids"), step_definition_ids);
        cucumber::messages::from_json(json, camelize("step_match_arguments_lists"), step_match_arguments_lists);
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
}
