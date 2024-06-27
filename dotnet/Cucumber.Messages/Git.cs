using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Git message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * Information about Git, provided by the Build/CI server as environment
 * variables.
 */
// Generated code
public sealed class Git {
    public string Remote { get; private set; }
    public string Revision { get; private set; }
    public string? Branch { get; private set; }
    public string? Tag { get; private set; }

    public Git(
        string remote,
        string revision,
        string branch,
        string tag
    ) 
    {
        this.Remote = remote;
        this.Revision = revision;
        this.Branch = branch;
        this.Tag = tag;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Git that = (Git) o;
        return 
            Remote.Equals(that.Remote) &&         
            Revision.Equals(that.Revision) &&         
            Object.Equals(Branch, that.Branch) &&         
            Object.Equals(Tag, that.Tag);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Remote.GetHashCode();
        hash = hash * 31 + Revision.GetHashCode();
        hash = hash * 31 + Branch?.GetHashCode()?? 0;
        hash = hash * 31 + Tag?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "Git{" +
            "remote=" + Remote +
            ", revision=" + Revision +
            ", branch=" + Branch +
            ", tag=" + Tag +
            '}';
    }
}
