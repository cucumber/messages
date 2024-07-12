using System;
using System.Collections.Generic;

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

public sealed class Ci 
{
    /**
     * Name of the CI product, e.g. "Jenkins", "CircleCI" etc.
     */
    public string Name { get; private set; }
    /**
     * Link to the build
     */
    public string Url { get; private set; }
    /**
     * The build number. Some CI servers use non-numeric build numbers, which is why this is a string
     */
    public string BuildNumber { get; private set; }
    public Git Git { get; private set; }


    public Ci(
        string name,
        string url,
        string buildNumber,
        Git git
    ) 
    {
              RequireNonNull<string>(name, "Name", "Ci.Name cannot be null");
        this.Name = name;
              this.Url = url;
              this.BuildNumber = buildNumber;
              this.Git = git;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Ci that = (Ci) o;
        return 
            Name.Equals(that.Name) &&         
            Object.Equals(Url, that.Url) &&         
            Object.Equals(BuildNumber, that.BuildNumber) &&         
            Object.Equals(Git, that.Git);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Name != null)
          hash = hash * 31 + Name.GetHashCode();
        if (Url != null)
          hash = hash * 31 + Url.GetHashCode();
        if (BuildNumber != null)
          hash = hash * 31 + BuildNumber.GetHashCode();
        if (Git != null)
          hash = hash * 31 + Git.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Ci{" +
            "name=" + Name +
            ", url=" + Url +
            ", buildNumber=" + BuildNumber +
            ", git=" + Git +
            '}';
    }

    private static T Require<T>(T property, string propertyName, string errorMessage)
    {
      RequireNonNull<T>(property, propertyName, errorMessage);
      return property;
    }
    private static void RequireNonNull<T>(T property, string propertyName, string errorMessage) 
    {
      if (property == null) throw new ArgumentNullException(propertyName, errorMessage);
    }
}
