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
#include <memory>
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
    // Generated code

    struct Envelope
    {
        std::optional<std::shared_ptr<Attachment>> attachment;
        std::optional<std::shared_ptr<ExternalAttachment>> externalAttachment;
        std::optional<std::shared_ptr<GherkinDocument>> gherkinDocument;
        std::optional<std::shared_ptr<Hook>> hook;
        std::optional<std::shared_ptr<Meta>> meta;
        std::optional<std::shared_ptr<ParameterType>> parameterType;
        std::optional<std::shared_ptr<ParseError>> parseError;
        std::optional<std::shared_ptr<Pickle>> pickle;
        std::optional<std::shared_ptr<Suggestion>> suggestion;
        std::optional<std::shared_ptr<Source>> source;
        std::optional<std::shared_ptr<StepDefinition>> stepDefinition;
        std::optional<std::shared_ptr<TestCase>> testCase;
        std::optional<std::shared_ptr<TestCaseFinished>> testCaseFinished;
        std::optional<std::shared_ptr<TestCaseStarted>> testCaseStarted;
        std::optional<std::shared_ptr<TestRunFinished>> testRunFinished;
        std::optional<std::shared_ptr<TestRunStarted>> testRunStarted;
        std::optional<std::shared_ptr<TestStepFinished>> testStepFinished;
        std::optional<std::shared_ptr<TestStepStarted>> testStepStarted;
        std::optional<std::shared_ptr<TestRunHookStarted>> testRunHookStarted;
        std::optional<std::shared_ptr<TestRunHookFinished>> testRunHookFinished;
        std::optional<std::shared_ptr<UndefinedParameterType>> undefinedParameterType;

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
