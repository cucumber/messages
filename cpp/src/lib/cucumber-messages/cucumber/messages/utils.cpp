#include <cucumber/messages/utils.hpp>

namespace cucumber::messages {

// https://codereview.stackexchange.com/questions/263749/codewars-kata-converting-snake-case-identifiers-to-camelcase-in-c
std::string
camelize(std::string s, bool initial_tail)
{
    std::size_t n = 0;
    bool tail = initial_tail;

    for (unsigned char c : s) {
        if (c == '-' || c == '_') {
            tail = false;
        } else if (tail) {
            s[n++] = c;
        } else {
            tail = true;
            s[n++] = std::toupper(c);
        }
    }

    s.resize(n);

    return s;
}

}
