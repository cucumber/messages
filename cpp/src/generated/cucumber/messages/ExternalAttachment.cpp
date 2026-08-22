#include "cucumber/messages/ExternalAttachment.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string ExternalAttachment::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "url=", url);
        cucumber::messages::to_string(oss, ", mediaType=", mediaType);
        cucumber::messages::to_string(oss, ", testCaseStartedId=", testCaseStartedId);
        cucumber::messages::to_string(oss, ", testStepId=", testStepId);
        cucumber::messages::to_string(oss, ", testRunHookStartedId=", testRunHookStartedId);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);

        return oss.str();
    }

    void ExternalAttachment::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "url", url);
        cucumber::messages::to_json(json, "mediaType", mediaType);
        cucumber::messages::to_json(json, "testCaseStartedId", testCaseStartedId);
        cucumber::messages::to_json(json, "testStepId", testStepId);
        cucumber::messages::to_json(json, "testRunHookStartedId", testRunHookStartedId);
        cucumber::messages::to_json(json, "timestamp", timestamp);
    }

    void ExternalAttachment::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "url", url);
        cucumber::messages::from_json(json, "mediaType", mediaType);
        cucumber::messages::from_json(json, "testCaseStartedId", testCaseStartedId);
        cucumber::messages::from_json(json, "testStepId", testStepId);
        cucumber::messages::from_json(json, "testRunHookStartedId", testRunHookStartedId);
        cucumber::messages::from_json(json, "timestamp", timestamp);
    }

    std::string ExternalAttachment::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const ExternalAttachment& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const ExternalAttachment& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, ExternalAttachment& msg)
    {
        msg.from_json(json);
    }
}
