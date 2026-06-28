
#include "cucumber/messages/parameter_type.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string parameter_type::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "name=", name);
        cucumber::messages::to_string(oss, ", regular_expressions=", regular_expressions);
        cucumber::messages::to_string(oss, ", prefer_for_regular_expression_match=", prefer_for_regular_expression_match);
        cucumber::messages::to_string(oss, ", use_for_snippets=", use_for_snippets);
        cucumber::messages::to_string(oss, ", id=", id);
        cucumber::messages::to_string(oss, ", source_reference=", source_reference);

        return oss.str();
    }

    void parameter_type::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("name"), name);
        cucumber::messages::to_json(json, camelize("regular_expressions"), regular_expressions);
        cucumber::messages::to_json(json, camelize("prefer_for_regular_expression_match"), prefer_for_regular_expression_match);
        cucumber::messages::to_json(json, camelize("use_for_snippets"), use_for_snippets);
        cucumber::messages::to_json(json, camelize("id"), id);
        cucumber::messages::to_json(json, camelize("source_reference"), source_reference);
    }

    void parameter_type::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("name"), name);
        cucumber::messages::from_json(json, camelize("regular_expressions"), regular_expressions);
        cucumber::messages::from_json(json, camelize("prefer_for_regular_expression_match"), prefer_for_regular_expression_match);
        cucumber::messages::from_json(json, camelize("use_for_snippets"), use_for_snippets);
        cucumber::messages::from_json(json, camelize("id"), id);
        cucumber::messages::from_json(json, camelize("source_reference"), source_reference);
    }

    std::string parameter_type::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const parameter_type& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const parameter_type& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, parameter_type& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<parameter_type>& msg)
    {
        msg = std::make_shared<parameter_type>();
        msg->from_json(json);
    }
}
