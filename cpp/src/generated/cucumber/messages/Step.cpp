#include "cucumber/messages/Step.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Step::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", keyword=", keyword);
        cucumber::messages::to_string(oss, ", keywordType=", keywordType);
        cucumber::messages::to_string(oss, ", text=", text);
        cucumber::messages::to_string(oss, ", docString=", docString);
        cucumber::messages::to_string(oss, ", dataTable=", dataTable);
        cucumber::messages::to_string(oss, ", id=", id);

        return oss.str();
    }

    void Step::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "location", location);
        cucumber::messages::to_json(json, "keyword", keyword);
        cucumber::messages::to_json(json, "keywordType", keywordType);
        cucumber::messages::to_json(json, "text", text);
        cucumber::messages::to_json(json, "docString", docString);
        cucumber::messages::to_json(json, "dataTable", dataTable);
        cucumber::messages::to_json(json, "id", id);
    }

    void Step::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "location", location);
        cucumber::messages::from_json(json, "keyword", keyword);
        cucumber::messages::from_json(json, "keywordType", keywordType);
        cucumber::messages::from_json(json, "text", text);
        cucumber::messages::from_json(json, "docString", docString);
        cucumber::messages::from_json(json, "dataTable", dataTable);
        cucumber::messages::from_json(json, "id", id);
    }

    std::string Step::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Step& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Step& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Step& msg)
    {
        msg.from_json(json);
    }
}
