#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/envelope.hpp>

namespace cucumber::messages {

std::string
envelope::to_string() const
{
    std::ostringstream oss;

    oss
    << "attachment=" << attachment
    << ", gherkin_document=" << gherkin_document
    << ", hook=" << hook
    << ", meta=" << meta
    << ", parameter_type=" << parameter_type
    << ", parse_error=" << parse_error
    << ", pickle=" << pickle
    << ", source=" << source
    << ", step_definition=" << step_definition
    << ", test_case=" << test_case
    << ", test_case_finished=" << test_case_finished
    << ", test_case_started=" << test_case_started
    << ", test_run_finished=" << test_run_finished
    << ", test_run_started=" << test_run_started
    << ", test_step_finished=" << test_step_finished
    << ", test_step_started=" << test_step_started
    << ", undefined_parameter_type=" << undefined_parameter_type
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const envelope& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const envelope& m)
{
    j = json{
        { "attachment", m.attachment },
        { "gherkin_document", m.gherkin_document },
        { "hook", m.hook },
        { "meta", m.meta },
        { "parameter_type", m.parameter_type },
        { "parse_error", m.parse_error },
        { "pickle", m.pickle },
        { "source", m.source },
        { "step_definition", m.step_definition },
        { "test_case", m.test_case },
        { "test_case_finished", m.test_case_finished },
        { "test_case_started", m.test_case_started },
        { "test_run_finished", m.test_run_finished },
        { "test_run_started", m.test_run_started },
        { "test_step_finished", m.test_step_finished },
        { "test_step_started", m.test_step_started },
        { "undefined_parameter_type", m.undefined_parameter_type }
    };
}

}
