#include "cucumber/messages/PickleTableCell.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string PickleTableCell::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "value=", value);

        return oss.str();
    }

    void PickleTableCell::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "value", value);
    }

    void PickleTableCell::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "value", value);
    }

    std::string PickleTableCell::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const PickleTableCell& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const PickleTableCell& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, PickleTableCell& msg)
    {
        msg.from_json(json);
    }
}
