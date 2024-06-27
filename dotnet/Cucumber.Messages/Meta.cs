using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Meta message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * This message contains meta information about the environment. Consumers can use
 * this for various purposes.
 */
// Generated code
public sealed class Meta {
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
    public Ci? Ci { get; private set; }

    public Meta(
        string protocolVersion,
        Product implementation,
        Product runtime,
        Product os,
        Product cpu,
        Ci ci
    ) 
    {
        this.ProtocolVersion = protocolVersion;
        this.Implementation = implementation;
        this.Runtime = runtime;
        this.Os = os;
        this.Cpu = cpu;
        this.Ci = ci;
    }

    public override boolean Equals(Object o) {
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

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + ProtocolVersion.GetHashCode();
        hash = hash * 31 + Implementation.GetHashCode();
        hash = hash * 31 + Runtime.GetHashCode();
        hash = hash * 31 + Os.GetHashCode();
        hash = hash * 31 + Cpu.GetHashCode();
        hash = hash * 31 + Ci?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "Meta{" +
            "protocolVersion=" + ProtocolVersion +
            ", implementation=" + Implementation +
            ", runtime=" + Runtime +
            ", os=" + Os +
            ", cpu=" + Cpu +
            ", ci=" + Ci +
            '}';
    }
}
