using Io.Cucumber.Messages.Types;
using System;
using System.Collections.Generic;
using System.Data;
using System.Text;

namespace Cucumber.Messages
{
    public class Converters
    {
        private static DateTime EpochStart = new DateTime(1970, 1, 1, 0, 0, 0, 0, System.DateTimeKind.Utc);
        private static long NanoSecondsPerTick = 100L;

        public static Timestamp ToTimestamp(DateTime dateTime)
        {
            var timeSpan = (dateTime.Subtract(EpochStart));
            long seconds = timeSpan.Ticks / TimeSpan.TicksPerSecond;
            long nanos = (timeSpan.Ticks % TimeSpan.TicksPerSecond) * NanoSecondsPerTick;
            return new Timestamp(
                seconds,
                nanos);
        }

        public static Duration ToDuration(TimeSpan timeSpan)
        {
            return new Duration(
                (long) timeSpan.TotalSeconds,
                (timeSpan.Ticks % TimeSpan.TicksPerSecond) * NanoSecondsPerTick);
        }

        public static DateTime ToDateTime(Timestamp timestamp)
        {
            var seconds = timestamp.Seconds;
            var time = EpochStart.AddSeconds(seconds).ToUniversalTime();
            time = time.AddTicks(timestamp.Nanos / NanoSecondsPerTick);

            return time;
        }

        public static TimeSpan ToTimeSpan(Duration duration)
        {
            var ts = new TimeSpan(0, 0, 0, (int)duration.Seconds);
            ts = ts.Add(TimeSpan.FromTicks(duration.Nanos / NanoSecondsPerTick));

            return ts;
        }
    }
}
