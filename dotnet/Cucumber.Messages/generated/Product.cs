using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Product message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * Used to describe various properties of Meta
 */

public sealed class Product 
{
    /**
     * The product name
     */
    public string Name { get; private set; }
    /**
     * The product version
     */
    public string Version { get; private set; }


    public Product(
        string name,
        string version
    ) 
    {
        RequireNonNull<string>(name, "Name", "Product.Name cannot be null");
        this.Name = name;
        this.Version = version;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Product that = (Product) o;
        return 
            Name.Equals(that.Name) &&         
            Object.Equals(Version, that.Version);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Name != null)
          hash = hash * 31 + Name.GetHashCode();
        if (Version != null)
          hash = hash * 31 + Version.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Product{" +
            "name=" + Name +
            ", version=" + Version +
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
