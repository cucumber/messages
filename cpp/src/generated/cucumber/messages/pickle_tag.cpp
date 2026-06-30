
#include "cucumber/messages/pickle_tag.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string pickle_tag::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "name=", name);
        cucumber::messages::to_string(oss, ", ast_node_id=", ast_node_id);

        return oss.str();
    }

    void pickle_tag::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("name"), name);
        cucumber::messages::to_json(json, camelize("ast_node_id"), ast_node_id);
    }

    void pickle_tag::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("name"), name);
        cucumber::messages::from_json(json, camelize("ast_node_id"), ast_node_id);
    }

    std::string pickle_tag::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const pickle_tag& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const pickle_tag& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, pickle_tag& msg)
    {
        msg.from_json(json);
    }
}
