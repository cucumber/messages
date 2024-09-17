
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the ParameterType message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record ParameterType 
{
    /**
     * The name is unique, so we don't need an id.
     */
    public string Name { get; }
    public ImmutableArray<string> RegularExpressions { get; }
    public bool PreferForRegularExpressionMatch { get; }
    public bool UseForSnippets { get; }
    public string Id { get; }
    public SourceReference? SourceReference { get; }


    public ParameterType(
        string name,
        ImmutableArray<string> regularExpressions,
        bool preferForRegularExpressionMatch,
        bool useForSnippets,
        string id,
        SourceReference? sourceReference
    ) 
    {
        Name = name ?? throw new ArgumentNullException("Name", "ParameterType.Name cannot be null");
        RegularExpressions = regularExpressions;
        PreferForRegularExpressionMatch = preferForRegularExpressionMatch;
        UseForSnippets = useForSnippets;
        Id = id ?? throw new ArgumentNullException("Id", "ParameterType.Id cannot be null");
        SourceReference = sourceReference;
    }
}
