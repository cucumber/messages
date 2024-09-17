
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Step message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A step
 */

public sealed record Step 
{
    /**
     * The location of the steps' `keyword`
     */
    public Location Location { get; }
    /**
     * The actual keyword as it appeared in the source.
     */
    public string Keyword { get; }
    /**
     * The test phase signalled by the keyword: Context definition (Given), Action performance (When), Outcome assertion (Then). Other keywords signal Continuation (And and But) from a prior keyword. Please note that all translations which a dialect maps to multiple keywords (`*` is in this category for all dialects), map to 'Unknown'.
     */
    public StepKeywordType? KeywordType { get; }
    public string Text { get; }
    public DocString? DocString { get; }
    public DataTable? DataTable { get; }
    /**
     * Unique ID to be able to reference the Step from PickleStep
     */
    public string Id { get; }


    public Step(
        Location location,
        string keyword,
        StepKeywordType? keywordType,
        string text,
        DocString? docString,
        DataTable? dataTable,
        string id
    ) 
    {
        Location = location ?? throw new ArgumentNullException("Location", "Step.Location cannot be null");
        Keyword = keyword ?? throw new ArgumentNullException("Keyword", "Step.Keyword cannot be null");
        KeywordType = keywordType;
        Text = text ?? throw new ArgumentNullException("Text", "Step.Text cannot be null");
        DocString = docString;
        DataTable = dataTable;
        Id = id ?? throw new ArgumentNullException("Id", "Step.Id cannot be null");
    }
}
