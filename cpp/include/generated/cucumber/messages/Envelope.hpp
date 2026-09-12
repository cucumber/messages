#ifndef CUCUMBER_MESSAGES_ENVELOPE_HPP
#define CUCUMBER_MESSAGES_ENVELOPE_HPP

#include "cucumber/messages/Attachment.hpp"
#include "cucumber/messages/ExternalAttachment.hpp"
#include "cucumber/messages/GherkinDocument.hpp"
#include "cucumber/messages/Hook.hpp"
#include "cucumber/messages/Meta.hpp"
#include "cucumber/messages/ParameterType.hpp"
#include "cucumber/messages/ParseError.hpp"
#include "cucumber/messages/Pickle.hpp"
#include "cucumber/messages/Source.hpp"
#include "cucumber/messages/StepDefinition.hpp"
#include "cucumber/messages/Suggestion.hpp"
#include "cucumber/messages/TestCase.hpp"
#include "cucumber/messages/TestCaseFinished.hpp"
#include "cucumber/messages/TestCaseStarted.hpp"
#include "cucumber/messages/TestRunFinished.hpp"
#include "cucumber/messages/TestRunHookFinished.hpp"
#include "cucumber/messages/TestRunHookStarted.hpp"
#include "cucumber/messages/TestRunStarted.hpp"
#include "cucumber/messages/TestStepFinished.hpp"
#include "cucumber/messages/TestStepStarted.hpp"
#include "cucumber/messages/UndefinedParameterType.hpp"
#include "nlohmann/json_fwd.hpp"
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Envelope message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //

    struct Envelope
    {
        std::optional<Attachment> attachment;
        std::optional<ExternalAttachment> externalAttachment;
        std::optional<GherkinDocument> gherkinDocument;
        std::optional<Hook> hook;
        std::optional<Meta> meta;
        std::optional<ParameterType> parameterType;
        std::optional<ParseError> parseError;
        std::optional<Pickle> pickle;
        std::optional<Suggestion> suggestion;
        std::optional<Source> source;
        std::optional<StepDefinition> stepDefinition;
        std::optional<TestCase> testCase;
        std::optional<TestCaseFinished> testCaseFinished;
        std::optional<TestCaseStarted> testCaseStarted;
        std::optional<TestRunFinished> testRunFinished;
        std::optional<TestRunStarted> testRunStarted;
        std::optional<TestStepFinished> testStepFinished;
        std::optional<TestStepStarted> testStepStarted;
        std::optional<TestRunHookStarted> testRunHookStarted;
        std::optional<TestRunHookFinished> testRunHookFinished;
        std::optional<UndefinedParameterType> undefinedParameterType;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Envelope& msg);

    void to_json(nlohmann::json& json, const Envelope& msg);
    void from_json(const nlohmann::json& json, Envelope& msg);
}

#endif
