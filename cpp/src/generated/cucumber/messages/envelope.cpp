
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
        if (attachment.has_value())
        {
            json[camelize("attachment")] = attachment;
        }
        if (external_attachment.has_value())
        {
            json[camelize("external_attachment")] = external_attachment;
        }
        if (gherkin_document.has_value())
        {
            json[camelize("gherkin_document")] = gherkin_document;
        }
        if (hook.has_value())
        {
            json[camelize("hook")] = hook;
        }
        if (meta.has_value())
        {
            json[camelize("meta")] = meta;
        }
        if (parameter_type.has_value())
        {
            json[camelize("parameter_type")] = parameter_type;
        }
        if (parse_error.has_value())
        {
            json[camelize("parse_error")] = parse_error;
        }
        if (pickle.has_value())
        {
            json[camelize("pickle")] = pickle;
        }
        if (suggestion.has_value())
        {
            json[camelize("suggestion")] = suggestion;
        }
        if (source.has_value())
        {
            json[camelize("source")] = source;
        }
        if (step_definition.has_value())
        {
            json[camelize("step_definition")] = step_definition;
        }
        if (test_case.has_value())
        {
            json[camelize("test_case")] = test_case;
        }
        if (test_case_finished.has_value())
        {
            json[camelize("test_case_finished")] = test_case_finished;
        }
        if (test_case_started.has_value())
        {
            json[camelize("test_case_started")] = test_case_started;
        }
        if (test_run_finished.has_value())
        {
            json[camelize("test_run_finished")] = test_run_finished;
        }
        if (test_run_started.has_value())
        {
            json[camelize("test_run_started")] = test_run_started;
        }
        if (test_step_finished.has_value())
        {
            json[camelize("test_step_finished")] = test_step_finished;
        }
        if (test_step_started.has_value())
        {
            json[camelize("test_step_started")] = test_step_started;
        }
        if (test_run_hook_started.has_value())
        {
            json[camelize("test_run_hook_started")] = test_run_hook_started;
        }
        if (test_run_hook_finished.has_value())
        {
            json[camelize("test_run_hook_finished")] = test_run_hook_finished;
        }
        if (undefined_parameter_type.has_value())
        {
            json[camelize("undefined_parameter_type")] = undefined_parameter_type;
        }
    }

    void envelope::from_json(const nlohmann::json& json)
    {
        if (attachment.has_value())
        {
            json.at(camelize("attachment")).get_to(attachment.emplace());
        }
        if (external_attachment.has_value())
        {
            json.at(camelize("external_attachment")).get_to(external_attachment.emplace());
        }
        if (gherkin_document.has_value())
        {
            json.at(camelize("gherkin_document")).get_to(gherkin_document.emplace());
        }
        if (hook.has_value())
        {
            json.at(camelize("hook")).get_to(hook.emplace());
        }
        if (meta.has_value())
        {
            json.at(camelize("meta")).get_to(meta.emplace());
        }
        if (parameter_type.has_value())
        {
            json.at(camelize("parameter_type")).get_to(parameter_type.emplace());
        }
        if (parse_error.has_value())
        {
            json.at(camelize("parse_error")).get_to(parse_error.emplace());
        }
        if (pickle.has_value())
        {
            json.at(camelize("pickle")).get_to(pickle.emplace());
        }
        if (suggestion.has_value())
        {
            json.at(camelize("suggestion")).get_to(suggestion.emplace());
        }
        if (source.has_value())
        {
            json.at(camelize("source")).get_to(source.emplace());
        }
        if (step_definition.has_value())
        {
            json.at(camelize("step_definition")).get_to(step_definition.emplace());
        }
        if (test_case.has_value())
        {
            json.at(camelize("test_case")).get_to(test_case.emplace());
        }
        if (test_case_finished.has_value())
        {
            json.at(camelize("test_case_finished")).get_to(test_case_finished.emplace());
        }
        if (test_case_started.has_value())
        {
            json.at(camelize("test_case_started")).get_to(test_case_started.emplace());
        }
        if (test_run_finished.has_value())
        {
            json.at(camelize("test_run_finished")).get_to(test_run_finished.emplace());
        }
        if (test_run_started.has_value())
        {
            json.at(camelize("test_run_started")).get_to(test_run_started.emplace());
        }
        if (test_step_finished.has_value())
        {
            json.at(camelize("test_step_finished")).get_to(test_step_finished.emplace());
        }
        if (test_step_started.has_value())
        {
            json.at(camelize("test_step_started")).get_to(test_step_started.emplace());
        }
        if (test_run_hook_started.has_value())
        {
            json.at(camelize("test_run_hook_started")).get_to(test_run_hook_started.emplace());
        }
        if (test_run_hook_finished.has_value())
        {
            json.at(camelize("test_run_hook_finished")).get_to(test_run_hook_finished.emplace());
        }
        if (undefined_parameter_type.has_value())
        {
            json.at(camelize("undefined_parameter_type")).get_to(undefined_parameter_type.emplace());
        }
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

    void from_json(const nlohmann::json& json, std::shared_ptr<envelope>& msg)
    {
        msg = std::make_shared<envelope>();
        msg->from_json(json);
    }
}
