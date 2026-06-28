
#include "cucumber/messages/pickle.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string pickle::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "id=", id);
        cucumber::messages::to_string(oss, ", uri=", uri);
        cucumber::messages::to_string(oss, ", location=", location);
        cucumber::messages::to_string(oss, ", name=", name);
        cucumber::messages::to_string(oss, ", language=", language);
        cucumber::messages::to_string(oss, ", steps=", steps);
        cucumber::messages::to_string(oss, ", tags=", tags);
        cucumber::messages::to_string(oss, ", ast_node_ids=", ast_node_ids);

        return oss.str();
    }

    void pickle::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("id"), id);
        cucumber::messages::to_json(json, camelize("uri"), uri);
        cucumber::messages::to_json(json, camelize("location"), location);
        cucumber::messages::to_json(json, camelize("name"), name);
        cucumber::messages::to_json(json, camelize("language"), language);
        cucumber::messages::to_json(json, camelize("steps"), steps);
        cucumber::messages::to_json(json, camelize("tags"), tags);
        cucumber::messages::to_json(json, camelize("ast_node_ids"), ast_node_ids);
    }

    void pickle::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("id"), id);
        cucumber::messages::from_json(json, camelize("uri"), uri);
        cucumber::messages::from_json(json, camelize("location"), location);
        cucumber::messages::from_json(json, camelize("name"), name);
        cucumber::messages::from_json(json, camelize("language"), language);
        cucumber::messages::from_json(json, camelize("steps"), steps);
        cucumber::messages::from_json(json, camelize("tags"), tags);
        cucumber::messages::from_json(json, camelize("ast_node_ids"), ast_node_ids);
    }

    std::string pickle::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const pickle& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const pickle& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, pickle& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<pickle>& msg)
    {
        msg = std::make_shared<pickle>();
        msg->from_json(json);
    }
}
