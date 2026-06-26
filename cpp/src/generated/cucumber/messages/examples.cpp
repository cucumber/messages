
#include "cucumber/messages/examples.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string examples::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", tags=", tags);
        cucumber::messages::to_string(oss, ", keyword=", keyword);
        cucumber::messages::to_string(oss, ", name=", name);
        cucumber::messages::to_string(oss, ", description=", description);
        cucumber::messages::to_string(oss, ", table_header=", table_header);
        cucumber::messages::to_string(oss, ", table_body=", table_body);
        cucumber::messages::to_string(oss, ", id=", id);

        return oss.str();
    }

    void examples::to_json(nlohmann::json& json) const
    {
        json[camelize("location")] = location;
        json[camelize("tags")] = tags;
        json[camelize("keyword")] = keyword;
        json[camelize("name")] = name;
        json[camelize("description")] = description;
        if (table_header.has_value())
        {
            json[camelize("table_header")] = table_header;
        }
        json[camelize("table_body")] = table_body;
        json[camelize("id")] = id;
    }

    void examples::from_json(const nlohmann::json& json)
    {
        json.at(camelize("location")).get_to(location);
        json.at(camelize("tags")).get_to(tags);
        json.at(camelize("keyword")).get_to(keyword);
        json.at(camelize("name")).get_to(name);
        json.at(camelize("description")).get_to(description);
        if (table_header.has_value())
        {
            json.at(camelize("table_header")).get_to(table_header.emplace());
        }
        json.at(camelize("table_body")).get_to(table_body);
        json.at(camelize("id")).get_to(id);
    }

    std::string examples::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const examples& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const examples& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, examples& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<examples>& msg)
    {
        msg = std::make_shared<examples>();
        msg->from_json(json);
    }
}
