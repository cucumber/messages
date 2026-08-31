#ifndef CUCUMBER_MESSAGES_DURATION_UTIL_HPP
#define CUCUMBER_MESSAGES_DURATION_UTIL_HPP

#include "cucumber/messages/Duration.hpp"
#include "cucumber/messages/Timestamp.hpp"
#include <cstddef>

namespace cucumber::messages
{
    constexpr std::size_t millisecondsPerSecond = 1000;
    constexpr std::size_t nanosecondsPerMillisecond = 1000000;
    constexpr std::size_t nanosecondsPerSecond = 1000000000;

    Duration operator-(const Timestamp& lhs, const Timestamp& rhs);

    Duration operator+(const Duration& lhs, const Duration& rhs);
}

#endif
