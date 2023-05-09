#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/attachment.hpp>
#include <cucumber/messages/gherkin_document.hpp>
#include <cucumber/messages/hook.hpp>
#include <cucumber/messages/meta.hpp>
#include <cucumber/messages/parameter_type.hpp>
#include <cucumber/messages/parse_error.hpp>
#include <cucumber/messages/pickle.hpp>
#include <cucumber/messages/source.hpp>
#include <cucumber/messages/step_definition.hpp>
#include <cucumber/messages/test_case.hpp>
#include <cucumber/messages/test_case_finished.hpp>
#include <cucumber/messages/test_case_started.hpp>
#include <cucumber/messages/test_run_finished.hpp>
#include <cucumber/messages/test_run_started.hpp>
#include <cucumber/messages/test_step_finished.hpp>
#include <cucumber/messages/test_step_started.hpp>
#include <cucumber/messages/undefined_parameter_type.hpp>

namespace cucumber::messages {

//
// Represents the Envelope message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// When removing a field, replace it with reserved, rather than deleting the line.
// When adding a field, add it to the end and increment the number by one.
// See https://developers.google.com/protocol-buffers/docs/proto#updating for details
//
// All the messages that are passed between different components/processes are Envelope
// messages.
//
// Generated code

struct envelope
{
    cucumber::messages::attachment attachment;
    cucumber::messages::gherkin_document gherkin_document;
    cucumber::messages::hook hook;
    cucumber::messages::meta meta;
    cucumber::messages::parameter_type parameter_type;
    cucumber::messages::parse_error parse_error;
    cucumber::messages::pickle pickle;
    cucumber::messages::source source;
    cucumber::messages::step_definition step_definition;
    cucumber::messages::test_case test_case;
    cucumber::messages::test_case_finished test_case_finished;
    cucumber::messages::test_case_started test_case_started;
    cucumber::messages::test_run_finished test_run_finished;
    cucumber::messages::test_run_started test_run_started;
    cucumber::messages::test_step_finished test_step_finished;
    cucumber::messages::test_step_started test_step_started;
    cucumber::messages::undefined_parameter_type undefined_parameter_type;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const envelope& msg);

using json = nlohmann::json;

void to_json(json& j, const envelope& m);

}
