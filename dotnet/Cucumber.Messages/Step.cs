using System;
using System.Collections.Generic;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Step message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A step
 */
// Generated code
public sealed class Step 
{
    /**
     * The location of the steps' `keyword`
     */
    public Location Location { get; private set; }
    /**
     * The actual keyword as it appeared in the source.
     */
    public string Keyword { get; private set; }
    /**
     * The test phase signalled by the keyword: Context definition (Given), Action performance (When), Outcome assertion (Then). Other keywords signal Continuation (And and But) from a prior keyword. Please note that all translations which a dialect maps to multiple keywords (`*` is in this category for all dialects), map to 'Unknown'.
     */
    public StepKeywordType KeywordType { get; private set; }
    public string Text { get; private set; }
    public DocString DocString { get; private set; }
    public DataTable DataTable { get; private set; }
    /**
     * Unique ID to be able to reference the Step from PickleStep
     */
    public string Id { get; private set; }


    public Step(
        Location location,
        string keyword,
        StepKeywordType keywordType,
        string text,
        DocString docString,
        DataTable dataTable,
        string id
    ) 
    {
              RequireNonNull<Location>(location, "Location", "Step.Location cannot be null");
        this.Location = location;
              RequireNonNull<string>(keyword, "Keyword", "Step.Keyword cannot be null");
        this.Keyword = keyword;
              this.KeywordType = keywordType;
              RequireNonNull<string>(text, "Text", "Step.Text cannot be null");
        this.Text = text;
              this.DocString = docString;
              this.DataTable = dataTable;
              RequireNonNull<string>(id, "Id", "Step.Id cannot be null");
        this.Id = id;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Step that = (Step) o;
        return 
            Location.Equals(that.Location) &&         
            Keyword.Equals(that.Keyword) &&         
            Object.Equals(KeywordType, that.KeywordType) &&         
            Text.Equals(that.Text) &&         
            Object.Equals(DocString, that.DocString) &&         
            Object.Equals(DataTable, that.DataTable) &&         
            Id.Equals(that.Id);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Location != null)
          hash = hash * 31 + Location.GetHashCode();
        if (Keyword != null)
          hash = hash * 31 + Keyword.GetHashCode();
        if (KeywordType != null)
          hash = hash * 31 + KeywordType.GetHashCode();
        if (Text != null)
          hash = hash * 31 + Text.GetHashCode();
        if (DocString != null)
          hash = hash * 31 + DocString.GetHashCode();
        if (DataTable != null)
          hash = hash * 31 + DataTable.GetHashCode();
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Step{" +
            "location=" + Location +
            ", keyword=" + Keyword +
            ", keywordType=" + KeywordType +
            ", text=" + Text +
            ", docString=" + DocString +
            ", dataTable=" + DataTable +
            ", id=" + Id +
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
