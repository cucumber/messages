using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Git message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * Information about Git, provided by the Build/CI server as environment
 * variables.
 */

public sealed class Git 
{
    public string Remote { get; private set; }
    public string Revision { get; private set; }
    public string Branch { get; private set; }
    public string Tag { get; private set; }


    public Git(
        string remote,
        string revision,
        string branch,
        string tag
    ) 
    {
              RequireNonNull<string>(remote, "Remote", "Git.Remote cannot be null");
        this.Remote = remote;
              RequireNonNull<string>(revision, "Revision", "Git.Revision cannot be null");
        this.Revision = revision;
              this.Branch = branch;
              this.Tag = tag;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Git that = (Git) o;
        return 
            Remote.Equals(that.Remote) &&         
            Revision.Equals(that.Revision) &&         
            Object.Equals(Branch, that.Branch) &&         
            Object.Equals(Tag, that.Tag);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Remote != null)
          hash = hash * 31 + Remote.GetHashCode();
        if (Revision != null)
          hash = hash * 31 + Revision.GetHashCode();
        if (Branch != null)
          hash = hash * 31 + Branch.GetHashCode();
        if (Tag != null)
          hash = hash * 31 + Tag.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Git{" +
            "remote=" + Remote +
            ", revision=" + Revision +
            ", branch=" + Branch +
            ", tag=" + Tag +
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
