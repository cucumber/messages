using Xunit;

namespace Cucumber.Messages.Specs;

public class ConvertersTests
{

    [Fact]
    public void ConvertsToAndFromTimestamp()
    {
        var current = DateTime.Parse("2024-06-29T17:29:47.1537257Z", null, System.Globalization.DateTimeStyles.RoundtripKind);
        var timestamp = Converters.ToTimestamp(current);

        var dt = Converters.ToDateTime(timestamp);

        Assert.Equal(current, dt);
    }

    [Fact]
    public void ConvertsToAndFromDuration()
    {
        var current = TimeSpan.FromSeconds(3.000161);
        var duration = Converters.ToDuration(current);

        var ts = Converters.ToTimeSpan(duration);

        Assert.Equal(current, ts);
    }
}
