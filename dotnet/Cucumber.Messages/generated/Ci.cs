
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Ci message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * CI environment
 */

public sealed record Ci 
{
    /**
     * Name of the CI product, e.g. "Jenkins", "CircleCI" etc.
     */
    public string Name { get; }
    /**
     * Link to the build
     */
    public string? Url { get; }
    /**
     * The build number. Some CI servers use non-numeric build numbers, which is why this is a string
     */
    public string? BuildNumber { get; }
    public Git? Git { get; }


    public Ci(
        string name,
        string? url,
        string? buildNumber,
        Git? git
    ) 
    {
        this.Name = name ?? throw new ArgumentNullException("Name", "Ci.Name cannot be null");
        this.Url = url;
        this.BuildNumber = buildNumber;
        this.Git = git;
    }
}
