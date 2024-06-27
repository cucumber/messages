using System;

namespace io.cucumber.messages.types;

// Generated code
public enum StepDefinitionPatternType {

    [Description("CUCUMBER_EXPRESSION")]
    CUCUMBER_EXPRESSION,

    [Description("REGULAR_EXPRESSION")]
    REGULAR_EXPRESSION;
    public static string Value(StepDefinitionPatternType v) {
        var attribute = v.GetType().GetField(v.ToString()).GetCustomAttribute<DescriptionAttribute>();
        return attribute == null ? v.ToString() : attribute.Description; 
    }
}
