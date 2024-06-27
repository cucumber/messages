using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Product message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * Used to describe various properties of Meta
 */
// Generated code
public sealed class Product {
    /**
     * The product name
     */
    public string Name { get; private set; }
    /**
     * The product version
     */
    public string? Version { get; private set; }

    public Product(
        string name,
        string version
    ) 
    {
        this.Name = name;
        this.Version = version;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Product that = (Product) o;
        return 
            Name.Equals(that.Name) &&         
            Object.Equals(Version, that.Version);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Name.GetHashCode();
        hash = hash * 31 + Version?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "Product{" +
            "name=" + Name +
            ", version=" + Version +
            '}';
    }
}
