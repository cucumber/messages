
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the PickleStepArgument message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * An optional argument
 */

public sealed record PickleStepArgument 
{
    public PickleDocString? DocString { get; }
    public PickleTable? DataTable { get; }


    public static PickleStepArgument Create(PickleDocString docString) 
    {
        return new PickleStepArgument(
            docString ?? throw new ArgumentNullException("DocString", "PickleStepArgument.DocString cannot be null"),
            null
        );
    }

    public static PickleStepArgument Create(PickleTable dataTable) 
    {
        return new PickleStepArgument(
            null,
            dataTable ?? throw new ArgumentNullException("DataTable", "PickleStepArgument.DataTable cannot be null")
        );
    }

    public PickleStepArgument(
        PickleDocString? docString,
        PickleTable? dataTable
    ) 
    {
        DocString = docString;
        DataTable = dataTable;
    }
}
