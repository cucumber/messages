#include "cucumber/messages/PickleStepArgument.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string PickleStepArgument::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "docString=", docString);
        cucumber::messages::to_string(oss, ", dataTable=", dataTable);

        return oss.str();
    }

    void PickleStepArgument::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "docString", docString);
        cucumber::messages::to_json(json, "dataTable", dataTable);
    }

    void PickleStepArgument::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "docString", docString);
        cucumber::messages::from_json(json, "dataTable", dataTable);
    }

    std::string PickleStepArgument::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const PickleStepArgument& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const PickleStepArgument& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, PickleStepArgument& msg)
    {
        msg.from_json(json);
    }
}
