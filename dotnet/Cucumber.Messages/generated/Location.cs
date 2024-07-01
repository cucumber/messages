using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Location message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * Points to a line and a column in a text file
 */

public sealed class Location 
{
    public long Line { get; private set; }
    public Nullable<long> Column { get; private set; }


    public Location(
        long line,
        Nullable<long> column
    ) 
    {
              RequireNonNull<long>(line, "Line", "Location.Line cannot be null");
        this.Line = line;
              this.Column = column;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Location that = (Location) o;
        return 
            Line.Equals(that.Line) &&         
            Object.Equals(Column, that.Column);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
          hash = hash * 31 + Line.GetHashCode();  
        if (Column.HasValue)
          hash = hash * 31 + Column.Value.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Location{" +
            "line=" + Line +
            (Column.HasValue ? ", column=" + Column.Value : "") +
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
