using System;
using System.Collections.Generic;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the PickleTable message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class PickleTable 
{
    public List<PickleTableRow> Rows { get; private set; }


    public PickleTable(
        List<PickleTableRow> rows
    ) 
    {
              RequireNonNull<List<PickleTableRow>>(rows, "Rows", "PickleTable.Rows cannot be null");
        this.Rows = new List<PickleTableRow>(rows);
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        PickleTable that = (PickleTable) o;
        return 
            Rows.Equals(that.Rows);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Rows != null)
          hash = hash * 31 + Rows.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "PickleTable{" +
            "rows=" + Rows +
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
