#include "cucumber/messages/Product.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Product::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "name=", name);
        cucumber::messages::to_string(oss, ", version=", version);

        return oss.str();
    }

    void Product::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "name", name);
        cucumber::messages::to_json(json, "version", version);
    }

    void Product::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "name", name);
        cucumber::messages::from_json(json, "version", version);
    }

    std::string Product::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Product& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Product& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Product& msg)
    {
        msg.from_json(json);
    }
}
