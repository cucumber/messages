#ifndef CUCUMBER_MESSAGES_ENVELOPE_HPP
#define CUCUMBER_MESSAGES_ENVELOPE_HPP

#include "cucumber/messages/attachment.hpp"
#include "cucumber/messages/external_attachment.hpp"
#include "cucumber/messages/gherkin_document.hpp"
#include "cucumber/messages/hook.hpp"
#include "cucumber/messages/meta.hpp"
#include "cucumber/messages/parameter_type.hpp"
#include "cucumber/messages/parse_error.hpp"
#include "cucumber/messages/pickle.hpp"
#include "cucumber/messages/source.hpp"
#include "cucumber/messages/step_definition.hpp"
#include "cucumber/messages/suggestion.hpp"
#include "cucumber/messages/test_case.hpp"
#include "cucumber/messages/test_case_finished.hpp"
#include "cucumber/messages/test_case_started.hpp"
#include "cucumber/messages/test_run_finished.hpp"
#include "cucumber/messages/test_run_hook_finished.hpp"
#include "cucumber/messages/test_run_hook_started.hpp"
#include "cucumber/messages/test_run_started.hpp"
#include "cucumber/messages/test_step_finished.hpp"
#include "cucumber/messages/test_step_started.hpp"
#include "cucumber/messages/undefined_parameter_type.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the Envelope message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct envelope
    {
        using shared_ptr = envelope;//std::shared_ptr<envelope>;

        std::optional<cucumber::messages::attachment::shared_ptr> attachment;
        std::optional<cucumber::messages::external_attachment::shared_ptr> external_attachment;
        std::optional<cucumber::messages::gherkin_document::shared_ptr> gherkin_document;
        std::optional<cucumber::messages::hook::shared_ptr> hook;
        std::optional<cucumber::messages::meta::shared_ptr> meta;
        std::optional<cucumber::messages::parameter_type::shared_ptr> parameter_type;
        std::optional<cucumber::messages::parse_error::shared_ptr> parse_error;
        std::optional<cucumber::messages::pickle::shared_ptr> pickle;
        std::optional<cucumber::messages::suggestion::shared_ptr> suggestion;
        std::optional<cucumber::messages::source::shared_ptr> source;
        std::optional<cucumber::messages::step_definition::shared_ptr> step_definition;
        std::optional<cucumber::messages::test_case::shared_ptr> test_case;
        std::optional<cucumber::messages::test_case_finished::shared_ptr> test_case_finished;
        std::optional<cucumber::messages::test_case_started::shared_ptr> test_case_started;
        std::optional<cucumber::messages::test_run_finished::shared_ptr> test_run_finished;
        std::optional<cucumber::messages::test_run_started::shared_ptr> test_run_started;
        std::optional<cucumber::messages::test_step_finished::shared_ptr> test_step_finished;
        std::optional<cucumber::messages::test_step_started::shared_ptr> test_step_started;
        std::optional<cucumber::messages::test_run_hook_started::shared_ptr> test_run_hook_started;
        std::optional<cucumber::messages::test_run_hook_finished::shared_ptr> test_run_hook_finished;
        std::optional<cucumber::messages::undefined_parameter_type::shared_ptr> undefined_parameter_type;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const envelope& msg);

    void to_json(nlohmann::json& json, const envelope& msg);
    void from_json(const nlohmann::json& json, envelope& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<envelope>& msg);

}

#endif
