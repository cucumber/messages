
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestCase message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * //// TestCases
 *
 * A `TestCase` contains a sequence of `TestStep`s.
 */

public sealed record TestCase 
{
    public string Id { get; }
    /**
     * The ID of the `Pickle` this `TestCase` is derived from.
     */
    public string PickleId { get; }
    public ImmutableArray<TestStep> TestSteps { get; }


    public TestCase(
        string id,
        string pickleId,
        ImmutableArray<TestStep> testSteps
    ) 
    {
        Id = id ?? throw new ArgumentNullException("Id", "TestCase.Id cannot be null");
        PickleId = pickleId ?? throw new ArgumentNullException("PickleId", "TestCase.PickleId cannot be null");
        TestSteps = testSteps;
    }
}
