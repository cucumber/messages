
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

public sealed record Meta 
{
    /**
     * The [SEMVER](https://semver.org/) version number of the protocol
     */
    public string ProtocolVersion { get; }
    /**
     * SpecFlow, Cucumber-JVM, Cucumber.js, Cucumber-Ruby, Behat etc.
     */
    public Product Implementation { get; }
    /**
     * Java, Ruby, Node.js etc
     */
    public Product Runtime { get; }
    /**
     * Windows, Linux, MacOS etc
     */
    public Product Os { get; }
    /**
     * 386, arm, amd64 etc
     */
    public Product Cpu { get; }
    public Ci? Ci { get; }


    public Meta(
        string protocolVersion,
        Product implementation,
        Product runtime,
        Product os,
        Product cpu,
        Ci? ci
    ) 
    {
        ProtocolVersion = protocolVersion ?? throw new ArgumentNullException("ProtocolVersion", "Meta.ProtocolVersion cannot be null");
        Implementation = implementation ?? throw new ArgumentNullException("Implementation", "Meta.Implementation cannot be null");
        Runtime = runtime ?? throw new ArgumentNullException("Runtime", "Meta.Runtime cannot be null");
        Os = os ?? throw new ArgumentNullException("Os", "Meta.Os cannot be null");
        Cpu = cpu ?? throw new ArgumentNullException("Cpu", "Meta.Cpu cannot be null");
        Ci = ci;
    }
}
