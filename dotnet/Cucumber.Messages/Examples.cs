using System;
using System.Collections.Generic;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Examples message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class Examples 
{
    /**
     * The location of the `Examples` keyword
     */
    public Location Location { get; private set; }
    public List<Tag> Tags { get; private set; }
    public string Keyword { get; private set; }
    public string Name { get; private set; }
    public string Description { get; private set; }
    public TableRow TableHeader { get; private set; }
    public List<TableRow> TableBody { get; private set; }
    public string Id { get; private set; }


    public Examples(
        Location location,
        List<Tag> tags,
        string keyword,
        string name,
        string description,
        TableRow tableHeader,
        List<TableRow> tableBody,
        string id
    ) 
    {
              RequireNonNull<Location>(location, "Location", "Examples.Location cannot be null");
        this.Location = location;
              RequireNonNull<List<Tag>>(tags, "Tags", "Examples.Tags cannot be null");
        this.Tags = new List<Tag>(tags);
              RequireNonNull<string>(keyword, "Keyword", "Examples.Keyword cannot be null");
        this.Keyword = keyword;
              RequireNonNull<string>(name, "Name", "Examples.Name cannot be null");
        this.Name = name;
              RequireNonNull<string>(description, "Description", "Examples.Description cannot be null");
        this.Description = description;
              this.TableHeader = tableHeader;
              RequireNonNull<List<TableRow>>(tableBody, "TableBody", "Examples.TableBody cannot be null");
        this.TableBody = new List<TableRow>(tableBody);
              RequireNonNull<string>(id, "Id", "Examples.Id cannot be null");
        this.Id = id;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Examples that = (Examples) o;
        return 
            Location.Equals(that.Location) &&         
            Tags.Equals(that.Tags) &&         
            Keyword.Equals(that.Keyword) &&         
            Name.Equals(that.Name) &&         
            Description.Equals(that.Description) &&         
            Object.Equals(TableHeader, that.TableHeader) &&         
            TableBody.Equals(that.TableBody) &&         
            Id.Equals(that.Id);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Location != null)
          hash = hash * 31 + Location.GetHashCode();
        if (Tags != null)
          hash = hash * 31 + Tags.GetHashCode();
        if (Keyword != null)
          hash = hash * 31 + Keyword.GetHashCode();
        if (Name != null)
          hash = hash * 31 + Name.GetHashCode();
        if (Description != null)
          hash = hash * 31 + Description.GetHashCode();
        if (TableHeader != null)
          hash = hash * 31 + TableHeader.GetHashCode();
        if (TableBody != null)
          hash = hash * 31 + TableBody.GetHashCode();
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Examples{" +
            "location=" + Location +
            ", tags=" + Tags +
            ", keyword=" + Keyword +
            ", name=" + Name +
            ", description=" + Description +
            ", tableHeader=" + TableHeader +
            ", tableBody=" + TableBody +
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
