
#include "cucumber/messages/gherkin_document.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string gherkin_document::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "uri=", uri);
        cucumber::messages::to_string(oss, ", feature=", feature);
        cucumber::messages::to_string(oss, ", comments=", comments);

        return oss.str();
    }

    void gherkin_document::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("uri"), uri);
        cucumber::messages::to_json(json, camelize("feature"), feature);
        cucumber::messages::to_json(json, camelize("comments"), comments);
    }

    void gherkin_document::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("uri"), uri);
        cucumber::messages::from_json(json, camelize("feature"), feature);
        cucumber::messages::from_json(json, camelize("comments"), comments);
    }

    std::string gherkin_document::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const gherkin_document& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const gherkin_document& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, gherkin_document& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<gherkin_document>& msg)
    {
        msg = std::make_shared<gherkin_document>();
        msg->from_json(json);
    }
}
