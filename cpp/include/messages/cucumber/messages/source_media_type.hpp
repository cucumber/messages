#pragma once

#include <string_view>

namespace cucumber::messages {

enum class source_media_type
{
    TEXT_X_CUCUMBER_GHERKIN_PLAIN,
    TEXT_X_CUCUMBER_GHERKIN_MARKDOWN
};

std::string_view
to_string(source_media_type v);

std::ostream&
operator<<(std::ostream& os, source_media_type v);

}
