package io.cucumber.messages;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * Marker annotation to provide a property name for an attribute.
 * <p>
 * Deserializing messages requires using the constructor parameter names.
 * However, debug symbols are not always available (e.g. in an optimized JLink
 * image). Instead, this annotation provides the property names.
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
