package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the Meta message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * This message contains meta information about the environment. Consumers can use
 * this for various purposes.
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class Meta {
    private final String protocolVersion;
    private final Product implementation;
    private final Product runtime;
    private final Product os;
    private final Product cpu;
    private final @Nullable Ci ci;

    public Meta(
        String protocolVersion,
        Product implementation,
        Product runtime,
        Product os,
        Product cpu,
        @Nullable Ci ci
    ) {
        this.protocolVersion = requireNonNull(protocolVersion, "Meta.protocolVersion cannot be null");
        this.implementation = requireNonNull(implementation, "Meta.implementation cannot be null");
        this.runtime = requireNonNull(runtime, "Meta.runtime cannot be null");
        this.os = requireNonNull(os, "Meta.os cannot be null");
        this.cpu = requireNonNull(cpu, "Meta.cpu cannot be null");
        this.ci = ci;
    }

    /**
     * The [SEMVER](https://semver.org/) version number of the protocol
     */
    public String getProtocolVersion() {
        return protocolVersion;
    }

    /**
     * SpecFlow, Cucumber-JVM, Cucumber.js, Cucumber-Ruby, Behat etc.
     */
    public Product getImplementation() {
        return implementation;
    }

    /**
     * Java, Ruby, Node.js etc
     */
    public Product getRuntime() {
        return runtime;
    }

    /**
     * Windows, Linux, MacOS etc
     */
    public Product getOs() {
        return os;
    }

    /**
     * 386, arm, amd64 etc
     */
    public Product getCpu() {
        return cpu;
    }

    public Optional<Ci> getCi() {
        return Optional.ofNullable(ci);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Meta that = (Meta) o;
        return 
            protocolVersion.equals(that.protocolVersion) &&         
            implementation.equals(that.implementation) &&         
            runtime.equals(that.runtime) &&         
            os.equals(that.os) &&         
            cpu.equals(that.cpu) &&         
            Objects.equals(ci, that.ci);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            protocolVersion,
            implementation,
            runtime,
            os,
            cpu,
            ci
        );
    }

    @Override
    public String toString() {
        return "Meta{" +
            "protocolVersion=" + protocolVersion +
            ", implementation=" + implementation +
            ", runtime=" + runtime +
            ", os=" + os +
            ", cpu=" + cpu +
            ", ci=" + ci +
            '}';
    }
}
