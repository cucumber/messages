package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the Product message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * Used to describe various properties of Meta
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class Product {
    private final String name;
    private final @Nullable String version;

    public Product(
        String name,
        @Nullable String version
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
