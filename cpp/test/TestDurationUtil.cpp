#include "cucumber/messages/Duration.hpp"
#include "cucumber/messages/DurationUtil.hpp"
#include "cucumber/messages/Timestamp.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <chrono>

namespace cucumber::messages
{
    namespace
    {
        TEST(TestDurationUtil, TimestampSubtractionToDuration)
        {
            auto duration1 = Timestamp{} - Timestamp{};
            auto duration2 = Timestamp{ 0, 30 } - Timestamp{ 0, 16 };
            auto duration3 = Timestamp{ 0, 100'000'000 } - Timestamp{ 0, 25'000'000 };
            auto duration4 = Timestamp{ 5, 100'000'000 } - Timestamp{ 3, 25'000'000 };
            auto duration5 = Timestamp{ 5, 100'000'000 } - Timestamp{ 3, 125'000'000 };

            EXPECT_THAT(duration1, testing::AllOf(testing::Field(&Duration::seconds, 0), testing::Field(&Duration::nanos, 0)));
            EXPECT_THAT(duration2, testing::AllOf(testing::Field(&Duration::seconds, 0), testing::Field(&Duration::nanos, 14)));
            EXPECT_THAT(duration3, testing::AllOf(testing::Field(&Duration::seconds, 0), testing::Field(&Duration::nanos, 75'000'000)));
            EXPECT_THAT(duration4, testing::AllOf(testing::Field(&Duration::seconds, 2), testing::Field(&Duration::nanos, 75'000'000)));
            EXPECT_THAT(duration5, testing::AllOf(testing::Field(&Duration::seconds, 1), testing::Field(&Duration::nanos, 975'000'000)));
        }
    }
}
