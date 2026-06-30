#include "cucumber/messages/utils.hpp"
#include <cctype>
#include <cstddef>
#include <string>

namespace cucumber::messages
{
    // https://codereview.stackexchange.com/questions/263749/codewars-kata-converting-snake-case-identifiers-to-camelcase-in-c
    std::string camelize(std::string str, bool initial_tail)
    {
        std::size_t writeIndex = 0;
        bool tail = initial_tail;

        for (const auto chr : str)
        {
            if (chr == '-' || chr == '_')
            {
                tail = false;
            }
            else if (tail)
            {
                str[writeIndex++] = chr;
            }
            else
            {
                tail = true;
                str[writeIndex++] = static_cast<char>(std::toupper(chr));
            }
        }

        str.resize(writeIndex);

        return str;
    }
}
