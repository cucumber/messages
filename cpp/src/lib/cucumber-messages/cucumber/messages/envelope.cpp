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

void
envelope::to_json(json& j) const
{
    j = json{
        { camelize("attachment"), attachment },
        { camelize("gherkin_document"), gherkin_document },
        { camelize("hook"), hook },
        { camelize("meta"), meta },
        { camelize("parameter_type"), parameter_type },
        { camelize("parse_error"), parse_error },
        { camelize("pickle"), pickle },
        { camelize("source"), source },
        { camelize("step_definition"), step_definition },
        { camelize("test_case"), test_case },
        { camelize("test_case_finished"), test_case_finished },
        { camelize("test_case_started"), test_case_started },
        { camelize("test_run_finished"), test_run_finished },
        { camelize("test_run_started"), test_run_started },
        { camelize("test_step_finished"), test_step_finished },
        { camelize("test_step_started"), test_step_started },
        { camelize("undefined_parameter_type"), undefined_parameter_type }
    };
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
