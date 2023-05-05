#include <unordered_map>

#include <cucumber/messages/source_media_type.hpp>

namespace cucumber::messages {

std::string_view
to_string(source_media_type v)
{
    using map_type = std::unordered_map<source_media_type, std::string_view>;

    static const map_type m = {
        { source_media_type::TEXT_X_CUCUMBER_GHERKIN_PLAIN, "text/x.cucumber.gherkin+plain" },
        { source_media_type::TEXT_X_CUCUMBER_GHERKIN_MARKDOWN, "text/x.cucumber.gherkin+markdown" }
    };

    return m.at(v);
}

std::ostream&
operator<<(std::ostream& os, source_media_type v)
{
    os << to_string(v);

    return os;
}

}
