using System;
using System.Collections.Generic;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the PickleTableRow message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class PickleTableRow 
{
    public List<PickleTableCell> Cells { get; private set; }


    public PickleTableRow(
        List<PickleTableCell> cells
    ) 
    {
              RequireNonNull<List<PickleTableCell>>(cells, "Cells", "PickleTableRow.Cells cannot be null");
        this.Cells = new List<PickleTableCell>(cells);
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        PickleTableRow that = (PickleTableRow) o;
        return 
            Cells.Equals(that.Cells);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Cells != null)
          hash = hash * 31 + Cells.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "PickleTableRow{" +
            "cells=" + Cells +
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
