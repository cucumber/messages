
#include "cucumber/messages/step_match_arguments_list.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string step_match_arguments_list::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "step_match_arguments=", step_match_arguments);

        return oss.str();
    }

    void step_match_arguments_list::to_json(nlohmann::json& json) const
    {
        json[camelize("step_match_arguments")] = step_match_arguments;
    }

    void step_match_arguments_list::from_json(const nlohmann::json& json)
    {
        json.at(camelize("step_match_arguments")).get_to(step_match_arguments);
    }

    std::string step_match_arguments_list::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const step_match_arguments_list& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const step_match_arguments_list& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, step_match_arguments_list& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<step_match_arguments_list>& msg)
    {
        msg = std::make_shared<step_match_arguments_list>();
        msg->from_json(json);
    }
}
