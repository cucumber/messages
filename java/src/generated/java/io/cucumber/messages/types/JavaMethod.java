package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the JavaMethod message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class JavaMethod {
    private final String className;
    private final String methodName;
    private final List<String> methodParameterTypes;

    public JavaMethod(
        String className,
        String methodName,
        List<String> methodParameterTypes
    ) {
        this.className = requireNonNull(className, "JavaMethod.className cannot be null");
        this.methodName = requireNonNull(methodName, "JavaMethod.methodName cannot be null");
        this.methodParameterTypes = List.copyOf(requireNonNull(methodParameterTypes, "JavaMethod.methodParameterTypes cannot be null"));
    }

    public String getClassName() {
        return className;
    }

    public String getMethodName() {
        return methodName;
    }

    public List<String> getMethodParameterTypes() {
        return methodParameterTypes;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        JavaMethod that = (JavaMethod) o;
        return 
            className.equals(that.className) &&         
            methodName.equals(that.methodName) &&         
            methodParameterTypes.equals(that.methodParameterTypes);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            className,
            methodName,
            methodParameterTypes
        );
    }

    @Override
    public String toString() {
        return "JavaMethod{" +
            "className=" + className +
            ", methodName=" + methodName +
            ", methodParameterTypes=" + methodParameterTypes +
            '}';
    }
}
