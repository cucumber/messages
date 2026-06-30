
#include "cucumber/messages/envelope.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string envelope::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "attachment=", attachment);
        cucumber::messages::to_string(oss, ", external_attachment=", external_attachment);
        cucumber::messages::to_string(oss, ", gherkin_document=", gherkin_document);
        cucumber::messages::to_string(oss, ", hook=", hook);
        cucumber::messages::to_string(oss, ", meta=", meta);
        cucumber::messages::to_string(oss, ", parameter_type=", parameter_type);
        cucumber::messages::to_string(oss, ", parse_error=", parse_error);
        cucumber::messages::to_string(oss, ", pickle=", pickle);
        cucumber::messages::to_string(oss, ", suggestion=", suggestion);
        cucumber::messages::to_string(oss, ", source=", source);
        cucumber::messages::to_string(oss, ", step_definition=", step_definition);
        cucumber::messages::to_string(oss, ", test_case=", test_case);
        cucumber::messages::to_string(oss, ", test_case_finished=", test_case_finished);
        cucumber::messages::to_string(oss, ", test_case_started=", test_case_started);
        cucumber::messages::to_string(oss, ", test_run_finished=", test_run_finished);
        cucumber::messages::to_string(oss, ", test_run_started=", test_run_started);
        cucumber::messages::to_string(oss, ", test_step_finished=", test_step_finished);
        cucumber::messages::to_string(oss, ", test_step_started=", test_step_started);
        cucumber::messages::to_string(oss, ", test_run_hook_started=", test_run_hook_started);
        cucumber::messages::to_string(oss, ", test_run_hook_finished=", test_run_hook_finished);
        cucumber::messages::to_string(oss, ", undefined_parameter_type=", undefined_parameter_type);

        return oss.str();
    }

    void envelope::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("attachment"), attachment);
        cucumber::messages::to_json(json, camelize("external_attachment"), external_attachment);
        cucumber::messages::to_json(json, camelize("gherkin_document"), gherkin_document);
        cucumber::messages::to_json(json, camelize("hook"), hook);
        cucumber::messages::to_json(json, camelize("meta"), meta);
        cucumber::messages::to_json(json, camelize("parameter_type"), parameter_type);
        cucumber::messages::to_json(json, camelize("parse_error"), parse_error);
        cucumber::messages::to_json(json, camelize("pickle"), pickle);
        cucumber::messages::to_json(json, camelize("suggestion"), suggestion);
        cucumber::messages::to_json(json, camelize("source"), source);
        cucumber::messages::to_json(json, camelize("step_definition"), step_definition);
        cucumber::messages::to_json(json, camelize("test_case"), test_case);
        cucumber::messages::to_json(json, camelize("test_case_finished"), test_case_finished);
        cucumber::messages::to_json(json, camelize("test_case_started"), test_case_started);
        cucumber::messages::to_json(json, camelize("test_run_finished"), test_run_finished);
        cucumber::messages::to_json(json, camelize("test_run_started"), test_run_started);
        cucumber::messages::to_json(json, camelize("test_step_finished"), test_step_finished);
        cucumber::messages::to_json(json, camelize("test_step_started"), test_step_started);
        cucumber::messages::to_json(json, camelize("test_run_hook_started"), test_run_hook_started);
        cucumber::messages::to_json(json, camelize("test_run_hook_finished"), test_run_hook_finished);
        cucumber::messages::to_json(json, camelize("undefined_parameter_type"), undefined_parameter_type);
    }

    void envelope::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("attachment"), attachment);
        cucumber::messages::from_json(json, camelize("external_attachment"), external_attachment);
        cucumber::messages::from_json(json, camelize("gherkin_document"), gherkin_document);
        cucumber::messages::from_json(json, camelize("hook"), hook);
        cucumber::messages::from_json(json, camelize("meta"), meta);
        cucumber::messages::from_json(json, camelize("parameter_type"), parameter_type);
        cucumber::messages::from_json(json, camelize("parse_error"), parse_error);
        cucumber::messages::from_json(json, camelize("pickle"), pickle);
        cucumber::messages::from_json(json, camelize("suggestion"), suggestion);
        cucumber::messages::from_json(json, camelize("source"), source);
        cucumber::messages::from_json(json, camelize("step_definition"), step_definition);
        cucumber::messages::from_json(json, camelize("test_case"), test_case);
        cucumber::messages::from_json(json, camelize("test_case_finished"), test_case_finished);
        cucumber::messages::from_json(json, camelize("test_case_started"), test_case_started);
        cucumber::messages::from_json(json, camelize("test_run_finished"), test_run_finished);
        cucumber::messages::from_json(json, camelize("test_run_started"), test_run_started);
        cucumber::messages::from_json(json, camelize("test_step_finished"), test_step_finished);
        cucumber::messages::from_json(json, camelize("test_step_started"), test_step_started);
        cucumber::messages::from_json(json, camelize("test_run_hook_started"), test_run_hook_started);
        cucumber::messages::from_json(json, camelize("test_run_hook_finished"), test_run_hook_finished);
        cucumber::messages::from_json(json, camelize("undefined_parameter_type"), undefined_parameter_type);
    }

    std::string envelope::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const envelope& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const envelope& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, envelope& msg)
    {
        msg.from_json(json);
    }
}
