using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Ci message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * CI environment
 */
// Generated code
public sealed class Ci {
    /**
     * Name of the CI product, e.g. "Jenkins", "CircleCI" etc.
     */
    public string Name { get; private set; }
    /**
     * Link to the build
     */
    public string? Url { get; private set; }
    /**
     * The build number. Some CI servers use non-numeric build numbers, which is why this is a string
     */
    public string? BuildNumber { get; private set; }
    public Git? Git { get; private set; }

    public Ci(
        string name,
        string url,
        string buildNumber,
        Git git
    ) 
    {
        this.Name = name;
        this.Url = url;
        this.BuildNumber = buildNumber;
        this.Git = git;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Ci that = (Ci) o;
        return 
            Name.Equals(that.Name) &&         
            Object.Equals(Url, that.Url) &&         
            Object.Equals(BuildNumber, that.BuildNumber) &&         
            Object.Equals(Git, that.Git);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Name.GetHashCode();
        hash = hash * 31 + Url?.GetHashCode()?? 0;
        hash = hash * 31 + BuildNumber?.GetHashCode()?? 0;
        hash = hash * 31 + Git?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "Ci{" +
            "name=" + Name +
            ", url=" + Url +
            ", buildNumber=" + BuildNumber +
            ", git=" + Git +
            '}';
    }
}
