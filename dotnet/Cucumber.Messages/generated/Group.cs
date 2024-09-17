
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Group message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record Group 
{
    public ImmutableArray<Group> Children { get; }
    public long? Start { get; }
    public string? Value { get; }


    public Group(
        ImmutableArray<Group> children,
        long? start,
        string? value
    ) 
    {
        Children = children;
        Start = start;
        Value = value;
    }
}
