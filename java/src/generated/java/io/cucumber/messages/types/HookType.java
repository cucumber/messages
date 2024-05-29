package io.cucumber.messages.types;

// Generated code
@SuppressWarnings("unused")
public enum HookType {

    BEFORE("BEFORE"),

    AFTER("AFTER"),

    BEFORE_STEP("BEFORE_STEP"),

    AFTER_STEP("AFTER_STEP");

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
