#include "cucumber/messages/PickleTable.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string PickleTable::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "argumentIndex=", argumentIndex);
        cucumber::messages::to_string(oss, ", rows=", rows);

        return oss.str();
    }

    void PickleTable::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "argumentIndex", argumentIndex);
        cucumber::messages::to_json(json, "rows", rows);
    }

    void PickleTable::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "argumentIndex", argumentIndex);
        cucumber::messages::from_json(json, "rows", rows);
    }

    std::string PickleTable::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const PickleTable& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const PickleTable& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, PickleTable& msg)
    {
        msg.from_json(json);
    }
}
