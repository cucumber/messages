using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Examples message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class Examples {
    /**
     * The location of the `Examples` keyword
     */
    public Location Location { get; private set; }
    public List<Tag> Tags { get; private set; }
    public string Keyword { get; private set; }
    public string Name { get; private set; }
    public string Description { get; private set; }
    public TableRow? TableHeader { get; private set; }
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
        this.Location = location;
        this.Tags = tags;
        this.Keyword = keyword;
        this.Name = name;
        this.Description = description;
        this.TableHeader = tableHeader;
        this.TableBody = tableBody;
        this.Id = id;
    }

    public override boolean Equals(Object o) {
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

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Location.GetHashCode();
        hash = hash * 31 + Tags.GetHashCode();
        hash = hash * 31 + Keyword.GetHashCode();
        hash = hash * 31 + Name.GetHashCode();
        hash = hash * 31 + Description.GetHashCode();
        hash = hash * 31 + TableHeader?.GetHashCode()?? 0;
        hash = hash * 31 + TableBody.GetHashCode();
        hash = hash * 31 + Id.GetHashCode();
        return hash;
    }

    public override string ToString() {
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
}
