package io.cucumber.messages;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * Marker annotation to provide a property name for an attribute.
 *
 * @implNote this functions effectively the same as Jacksons
 * {@code @JsonProperty}.
 * <p>
 * We are trying to solve a few problems here. We don't want a dependency on
 * Jackson as that could affect the system under test. Normally this isn't a
 * problem because Jackson can deserialize messages using the constructor
 * parameter names. However, when debug symbols are not available (e.g. in an
 * optimized JLink image) we can't use that trick. So instead we provide our
 * own annotation that provides property names. We can write a custom version
 * of Jacksons {@code ParameterNamesAnnotationIntrospector} to read our
 * annotations.
 */
@Target(ElementType.PARAMETER)
@Retention(RetentionPolicy.RUNTIME)
public @interface Property {

    /**
     * Returns the name of the property.
     *
     * @return the name of the property.
     */
    String value();
}
