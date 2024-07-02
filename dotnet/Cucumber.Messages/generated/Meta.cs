using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Meta message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * This message contains meta information about the environment. Consumers can use
 * this for various purposes.
 */

public sealed class Meta 
{
    /**
     * The [SEMVER](https://semver.org/) version number of the protocol
     */
    public string ProtocolVersion { get; private set; }
    /**
     * SpecFlow, Cucumber-JVM, Cucumber.js, Cucumber-Ruby, Behat etc.
     */
    public Product Implementation { get; private set; }
    /**
     * Java, Ruby, Node.js etc
     */
    public Product Runtime { get; private set; }
    /**
     * Windows, Linux, MacOS etc
     */
    public Product Os { get; private set; }
    /**
     * 386, arm, amd64 etc
     */
    public Product Cpu { get; private set; }
    public Ci Ci { get; private set; }


    public Meta(
        string protocolVersion,
        Product implementation,
        Product runtime,
        Product os,
        Product cpu,
        Ci ci
    ) 
    {
              RequireNonNull<string>(protocolVersion, "ProtocolVersion", "Meta.ProtocolVersion cannot be null");
        this.ProtocolVersion = protocolVersion;
              RequireNonNull<Product>(implementation, "Implementation", "Meta.Implementation cannot be null");
        this.Implementation = implementation;
              RequireNonNull<Product>(runtime, "Runtime", "Meta.Runtime cannot be null");
        this.Runtime = runtime;
              RequireNonNull<Product>(os, "Os", "Meta.Os cannot be null");
        this.Os = os;
              RequireNonNull<Product>(cpu, "Cpu", "Meta.Cpu cannot be null");
        this.Cpu = cpu;
              this.Ci = ci;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Meta that = (Meta) o;
        return 
            ProtocolVersion.Equals(that.ProtocolVersion) &&         
            Implementation.Equals(that.Implementation) &&         
            Runtime.Equals(that.Runtime) &&         
            Os.Equals(that.Os) &&         
            Cpu.Equals(that.Cpu) &&         
            Object.Equals(Ci, that.Ci);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (ProtocolVersion != null)
          hash = hash * 31 + ProtocolVersion.GetHashCode();
        if (Implementation != null)
          hash = hash * 31 + Implementation.GetHashCode();
        if (Runtime != null)
          hash = hash * 31 + Runtime.GetHashCode();
        if (Os != null)
          hash = hash * 31 + Os.GetHashCode();
        if (Cpu != null)
          hash = hash * 31 + Cpu.GetHashCode();
        if (Ci != null)
          hash = hash * 31 + Ci.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Meta{" +
            "protocolVersion=" + ProtocolVersion +
            ", implementation=" + Implementation +
            ", runtime=" + Runtime +
            ", os=" + Os +
            ", cpu=" + Cpu +
            ", ci=" + Ci +
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
