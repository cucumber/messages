
#include "cucumber/messages/product.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string product::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "name=", name);
        cucumber::messages::to_string(oss, ", version=", version);

        return oss.str();
    }

    void product::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("name"), name);
        cucumber::messages::to_json(json, camelize("version"), version);
    }

    void product::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("name"), name);
        cucumber::messages::from_json(json, camelize("version"), version);
    }

    std::string product::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const product& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const product& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, product& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<product>& msg)
    {
        msg = std::make_shared<product>();
        msg->from_json(json);
    }
}
