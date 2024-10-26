package io.cucumber.messages.types;

// Generated code
@SuppressWarnings("unused")
public enum HookType {

    BEFORE_TEST_RUN("BEFORE_TEST_RUN"),

    AFTER_TEST_RUN("AFTER_TEST_RUN"),

    BEFORE_TEST_CASE("BEFORE_TEST_CASE"),

    AFTER_TEST_CASE("AFTER_TEST_CASE"),

    BEFORE_TEST_STEP("BEFORE_TEST_STEP"),

    AFTER_TEST_STEP("AFTER_TEST_STEP");

    private final String value;

    HookType(String value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return this.value;
    }

    public String value() {
        return this.value;
    }

    public static HookType fromValue(String value) {
        for (HookType v : values()) {
            if (v.value.equals(value)) {
                return v;
            }
        }
        throw new IllegalArgumentException(value);
    }
}
