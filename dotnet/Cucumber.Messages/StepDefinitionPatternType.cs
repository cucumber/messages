using System;
using System.ComponentModel;
using System.Reflection;

namespace io.cucumber.messages.types;

// Generated code
public enum StepDefinitionPatternType {

    [Description("CUCUMBER_EXPRESSION")]
    CUCUMBER_EXPRESSION,

    [Description("REGULAR_EXPRESSION")]
    REGULAR_EXPRESSION
}

public static class StepDefinitionPatternTypeExtensions
{
    public static string Value(this StepDefinitionPatternType v) {
        var attribute = v.GetType().GetField(v.ToString()).GetCustomAttribute<DescriptionAttribute>();
        return attribute == null ? v.ToString() : attribute.Description; 
    }
}
