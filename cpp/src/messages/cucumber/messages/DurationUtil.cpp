#include "cucumber/messages/DurationUtil.hpp"
#include "cucumber/messages/Duration.hpp"
#include "cucumber/messages/Timestamp.hpp"
#include <chrono>
#include <ctime>

namespace cucumber::messages
{
    namespace
    {
        std::chrono::nanoseconds ToNanos(std::chrono::seconds seconds, std::chrono::nanoseconds nanos)
        {
            return std::chrono::duration_cast<std::chrono::nanoseconds>(seconds) + nanos;
        }

        std::chrono::nanoseconds TimestampToNanos(const Timestamp& timestamp)
        {
            return ToNanos(std::chrono::seconds(timestamp.seconds), std::chrono::nanoseconds(timestamp.nanos));
        }

        Duration ToDuration(std::chrono::nanoseconds millis)
        {
            return { millis.count() / nanosecondsPerSecond, millis.count() % nanosecondsPerSecond };
        }
    }

    Duration operator-(const Timestamp& lhs, const Timestamp& rhs)
    {
        const auto durationMillis = TimestampToNanos(lhs) - TimestampToNanos(rhs);
        return ToDuration(durationMillis);
    }

    Duration operator+(const Duration& lhs, const Duration& rhs)
    {
        const auto durationMillis = ToNanos(std::chrono::seconds(lhs.seconds), std::chrono::nanoseconds(lhs.nanos)) + ToNanos(std::chrono::seconds(rhs.seconds), std::chrono::nanoseconds(rhs.nanos));
        return ToDuration(durationMillis);
    }
}
