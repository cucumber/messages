using Xunit;

namespace Cucumber.Messages.Specs;

public class ProtocolVersionTest
{
    [Fact]
    public void ProtocolVersionIsCorrect()
    {
        Assert.Matches(@"\d+\.\d+\.\d+(-[0-9A-Za-z-](\.[0-9A-Za-z-])*)?", Cucumber.Messages.ProtocolVersion.Version);
    }
}
