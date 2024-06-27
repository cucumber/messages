using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the ParameterType message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class ParameterType {
    /**
     * The name is unique, so we don't need an id.
     */
    public string Name { get; private set; }
    public List<string> RegularExpressions { get; private set; }
    public bool PreferForRegularExpressionMatch { get; private set; }
    public bool UseForSnippets { get; private set; }
    public string Id { get; private set; }
    public SourceReference? SourceReference { get; private set; }

    public ParameterType(
        string name,
        List<string> regularExpressions,
        bool preferForRegularExpressionMatch,
        bool useForSnippets,
        string id,
        SourceReference sourceReference
    ) 
    {
        this.Name = name;
        this.RegularExpressions = regularExpressions;
        this.PreferForRegularExpressionMatch = preferForRegularExpressionMatch;
        this.UseForSnippets = useForSnippets;
        this.Id = id;
        this.SourceReference = sourceReference;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        ParameterType that = (ParameterType) o;
        return 
            Name.Equals(that.Name) &&         
            RegularExpressions.Equals(that.RegularExpressions) &&         
            PreferForRegularExpressionMatch.Equals(that.PreferForRegularExpressionMatch) &&         
            UseForSnippets.Equals(that.UseForSnippets) &&         
            Id.Equals(that.Id) &&         
            Object.Equals(SourceReference, that.SourceReference);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Name.GetHashCode();
        hash = hash * 31 + RegularExpressions.GetHashCode();
        hash = hash * 31 + PreferForRegularExpressionMatch.GetHashCode();
        hash = hash * 31 + UseForSnippets.GetHashCode();
        hash = hash * 31 + Id.GetHashCode();
        hash = hash * 31 + SourceReference?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "ParameterType{" +
            "name=" + Name +
            ", regularExpressions=" + RegularExpressions +
            ", preferForRegularExpressionMatch=" + PreferForRegularExpressionMatch +
            ", useForSnippets=" + UseForSnippets +
            ", id=" + Id +
            ", sourceReference=" + SourceReference +
            '}';
    }
}
