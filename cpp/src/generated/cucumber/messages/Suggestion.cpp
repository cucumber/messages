#include "cucumber/messages/Suggestion.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Suggestion::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "id=", id);
        cucumber::messages::to_string(oss, ", pickleStepId=", pickleStepId);
        cucumber::messages::to_string(oss, ", snippets=", snippets);

        return oss.str();
    }

    void Suggestion::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "id", id);
        cucumber::messages::to_json(json, "pickleStepId", pickleStepId);
        cucumber::messages::to_json(json, "snippets", snippets);
    }

    void Suggestion::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "id", id);
        cucumber::messages::from_json(json, "pickleStepId", pickleStepId);
        cucumber::messages::from_json(json, "snippets", snippets);
    }

    std::string Suggestion::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Suggestion& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Suggestion& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Suggestion& msg)
    {
        msg.from_json(json);
    }
}
