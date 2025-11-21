package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the JavaStackTraceElement message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class JavaStackTraceElement {
    private final String className;
    private final String fileName;
    private final String methodName;

    public JavaStackTraceElement(
        String className,
        String fileName,
        String methodName
    ) {
        this.className = requireNonNull(className, "JavaStackTraceElement.className cannot be null");
        this.fileName = requireNonNull(fileName, "JavaStackTraceElement.fileName cannot be null");
        this.methodName = requireNonNull(methodName, "JavaStackTraceElement.methodName cannot be null");
    }

    public String getClassName() {
        return className;
    }

    public String getFileName() {
        return fileName;
    }

    public String getMethodName() {
        return methodName;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        JavaStackTraceElement that = (JavaStackTraceElement) o;
        return 
            className.equals(that.className) &&         
            fileName.equals(that.fileName) &&         
            methodName.equals(that.methodName);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            className,
            fileName,
            methodName
        );
    }

    @Override
    public String toString() {
        return "JavaStackTraceElement{" +
            "className=" + className +
            ", fileName=" + fileName +
            ", methodName=" + methodName +
            '}';
    }
}
