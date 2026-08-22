#include "cucumber/messages/Envelope.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Envelope::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "attachment=", attachment);
        cucumber::messages::to_string(oss, ", externalAttachment=", externalAttachment);
        cucumber::messages::to_string(oss, ", gherkinDocument=", gherkinDocument);
        cucumber::messages::to_string(oss, ", hook=", hook);
        cucumber::messages::to_string(oss, ", meta=", meta);
        cucumber::messages::to_string(oss, ", parameterType=", parameterType);
        cucumber::messages::to_string(oss, ", parseError=", parseError);
        cucumber::messages::to_string(oss, ", pickle=", pickle);
        cucumber::messages::to_string(oss, ", suggestion=", suggestion);
        cucumber::messages::to_string(oss, ", source=", source);
        cucumber::messages::to_string(oss, ", stepDefinition=", stepDefinition);
        cucumber::messages::to_string(oss, ", testCase=", testCase);
        cucumber::messages::to_string(oss, ", testCaseFinished=", testCaseFinished);
        cucumber::messages::to_string(oss, ", testCaseStarted=", testCaseStarted);
        cucumber::messages::to_string(oss, ", testRunFinished=", testRunFinished);
        cucumber::messages::to_string(oss, ", testRunStarted=", testRunStarted);
        cucumber::messages::to_string(oss, ", testStepFinished=", testStepFinished);
        cucumber::messages::to_string(oss, ", testStepStarted=", testStepStarted);
        cucumber::messages::to_string(oss, ", testRunHookStarted=", testRunHookStarted);
        cucumber::messages::to_string(oss, ", testRunHookFinished=", testRunHookFinished);
        cucumber::messages::to_string(oss, ", undefinedParameterType=", undefinedParameterType);

        return oss.str();
    }

    void Envelope::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "attachment", attachment);
        cucumber::messages::to_json(json, "externalAttachment", externalAttachment);
        cucumber::messages::to_json(json, "gherkinDocument", gherkinDocument);
        cucumber::messages::to_json(json, "hook", hook);
        cucumber::messages::to_json(json, "meta", meta);
        cucumber::messages::to_json(json, "parameterType", parameterType);
        cucumber::messages::to_json(json, "parseError", parseError);
        cucumber::messages::to_json(json, "pickle", pickle);
        cucumber::messages::to_json(json, "suggestion", suggestion);
        cucumber::messages::to_json(json, "source", source);
        cucumber::messages::to_json(json, "stepDefinition", stepDefinition);
        cucumber::messages::to_json(json, "testCase", testCase);
        cucumber::messages::to_json(json, "testCaseFinished", testCaseFinished);
        cucumber::messages::to_json(json, "testCaseStarted", testCaseStarted);
        cucumber::messages::to_json(json, "testRunFinished", testRunFinished);
        cucumber::messages::to_json(json, "testRunStarted", testRunStarted);
        cucumber::messages::to_json(json, "testStepFinished", testStepFinished);
        cucumber::messages::to_json(json, "testStepStarted", testStepStarted);
        cucumber::messages::to_json(json, "testRunHookStarted", testRunHookStarted);
        cucumber::messages::to_json(json, "testRunHookFinished", testRunHookFinished);
        cucumber::messages::to_json(json, "undefinedParameterType", undefinedParameterType);
    }

    void Envelope::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "attachment", attachment);
        cucumber::messages::from_json(json, "externalAttachment", externalAttachment);
        cucumber::messages::from_json(json, "gherkinDocument", gherkinDocument);
        cucumber::messages::from_json(json, "hook", hook);
        cucumber::messages::from_json(json, "meta", meta);
        cucumber::messages::from_json(json, "parameterType", parameterType);
        cucumber::messages::from_json(json, "parseError", parseError);
        cucumber::messages::from_json(json, "pickle", pickle);
        cucumber::messages::from_json(json, "suggestion", suggestion);
        cucumber::messages::from_json(json, "source", source);
        cucumber::messages::from_json(json, "stepDefinition", stepDefinition);
        cucumber::messages::from_json(json, "testCase", testCase);
        cucumber::messages::from_json(json, "testCaseFinished", testCaseFinished);
        cucumber::messages::from_json(json, "testCaseStarted", testCaseStarted);
        cucumber::messages::from_json(json, "testRunFinished", testRunFinished);
        cucumber::messages::from_json(json, "testRunStarted", testRunStarted);
        cucumber::messages::from_json(json, "testStepFinished", testStepFinished);
        cucumber::messages::from_json(json, "testStepStarted", testStepStarted);
        cucumber::messages::from_json(json, "testRunHookStarted", testRunHookStarted);
        cucumber::messages::from_json(json, "testRunHookFinished", testRunHookFinished);
        cucumber::messages::from_json(json, "undefinedParameterType", undefinedParameterType);
    }

    std::string Envelope::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Envelope& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Envelope& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Envelope& msg)
    {
        msg.from_json(json);
    }
}
