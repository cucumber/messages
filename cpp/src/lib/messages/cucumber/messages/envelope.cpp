#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/envelope.hpp>

namespace cucumber::messages {

std::string
envelope::to_string() const
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

void
envelope::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("attachment"), attachment);
    cucumber::messages::to_json(j, camelize("external_attachment"), external_attachment);
    cucumber::messages::to_json(j, camelize("gherkin_document"), gherkin_document);
    cucumber::messages::to_json(j, camelize("hook"), hook);
    cucumber::messages::to_json(j, camelize("meta"), meta);
    cucumber::messages::to_json(j, camelize("parameter_type"), parameter_type);
    cucumber::messages::to_json(j, camelize("parse_error"), parse_error);
    cucumber::messages::to_json(j, camelize("pickle"), pickle);
    cucumber::messages::to_json(j, camelize("suggestion"), suggestion);
    cucumber::messages::to_json(j, camelize("source"), source);
    cucumber::messages::to_json(j, camelize("step_definition"), step_definition);
    cucumber::messages::to_json(j, camelize("test_case"), test_case);
    cucumber::messages::to_json(j, camelize("test_case_finished"), test_case_finished);
    cucumber::messages::to_json(j, camelize("test_case_started"), test_case_started);
    cucumber::messages::to_json(j, camelize("test_run_finished"), test_run_finished);
    cucumber::messages::to_json(j, camelize("test_run_started"), test_run_started);
    cucumber::messages::to_json(j, camelize("test_step_finished"), test_step_finished);
    cucumber::messages::to_json(j, camelize("test_step_started"), test_step_started);
    cucumber::messages::to_json(j, camelize("test_run_hook_started"), test_run_hook_started);
    cucumber::messages::to_json(j, camelize("test_run_hook_finished"), test_run_hook_finished);
    cucumber::messages::to_json(j, camelize("undefined_parameter_type"), undefined_parameter_type);
}

std::string
envelope::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const envelope& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const envelope& m)
{ m.to_json(j); }

}
