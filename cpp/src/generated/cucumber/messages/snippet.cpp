
#include "cucumber/messages/snippet.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string snippet::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "language=", language);
        cucumber::messages::to_string(oss, ", code=", code);

        return oss.str();
    }

    void snippet::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("language"), language);
        cucumber::messages::to_json(json, camelize("code"), code);
    }

    void snippet::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("language"), language);
        cucumber::messages::from_json(json, camelize("code"), code);
    }

    std::string snippet::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const snippet& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const snippet& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, snippet& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<snippet>& msg)
    {
        msg = std::make_shared<snippet>();
        msg->from_json(json);
    }
}
