using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the ParameterType message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class ParameterType 
{
    /**
     * The name is unique, so we don't need an id.
     */
    public string Name { get; private set; }
    public List<string> RegularExpressions { get; private set; }
    public bool PreferForRegularExpressionMatch { get; private set; }
    public bool UseForSnippets { get; private set; }
    public string Id { get; private set; }
    public SourceReference SourceReference { get; private set; }


    public ParameterType(
        string name,
        List<string> regularExpressions,
        bool preferForRegularExpressionMatch,
        bool useForSnippets,
        string id,
        SourceReference sourceReference
    ) 
    {
        RequireNonNull<string>(name, "Name", "ParameterType.Name cannot be null");
        this.Name = name;
        RequireNonNull<List<string>>(regularExpressions, "RegularExpressions", "ParameterType.RegularExpressions cannot be null");
        this.RegularExpressions = new List<string>(regularExpressions);        
        RequireNonNull<bool>(preferForRegularExpressionMatch, "PreferForRegularExpressionMatch", "ParameterType.PreferForRegularExpressionMatch cannot be null");
        this.PreferForRegularExpressionMatch = preferForRegularExpressionMatch;
        RequireNonNull<bool>(useForSnippets, "UseForSnippets", "ParameterType.UseForSnippets cannot be null");
        this.UseForSnippets = useForSnippets;
        RequireNonNull<string>(id, "Id", "ParameterType.Id cannot be null");
        this.Id = id;
        this.SourceReference = sourceReference;
    }

    public override bool Equals(Object o) 
    {
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

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Name != null)
          hash = hash * 31 + Name.GetHashCode();
        if (RegularExpressions != null)
          hash = hash * 31 + RegularExpressions.GetHashCode();
          hash = hash * 31 + PreferForRegularExpressionMatch.GetHashCode();  
          hash = hash * 31 + UseForSnippets.GetHashCode();  
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        if (SourceReference != null)
          hash = hash * 31 + SourceReference.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "ParameterType{" +
            "name=" + Name +
            ", regularExpressions=" + RegularExpressions +
            ", preferForRegularExpressionMatch=" + PreferForRegularExpressionMatch +
            ", useForSnippets=" + UseForSnippets +
            ", id=" + Id +
            ", sourceReference=" + SourceReference +
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
