package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the Product message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * Used to describe various properties of Meta
 */
// Generated code
@SuppressWarnings("unused")
public final class Product {
    private final String name;
    private final String version;

    public Product(
        String name,
        String version
    ) {
        this.name = requireNonNull(name, "Product.name cannot be null");
        this.version = version;
    }

    /**
     * The product name
     */
    public String getName() {
        return name;
    }

    /**
      * The product version
     */
    public Optional<String> getVersion() {
        return Optional.ofNullable(version);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Product that = (Product) o;
        return 
            name.equals(that.name) &&         
            Objects.equals(version, that.version);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            name,
            version
        );
    }

    @Override
    public String toString() {
        return "Product{" +
            "name=" + name +
            ", version=" + version +
            '}';
    }
}
