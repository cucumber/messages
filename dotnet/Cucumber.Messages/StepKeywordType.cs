using System;
using System.ComponentModel;
using System.Reflection;

namespace io.cucumber.messages.types;

// Generated code
public enum StepKeywordType {

    [Description("Unknown")]
    UNKNOWN,

    [Description("Context")]
    CONTEXT,

    [Description("Action")]
    ACTION,

    [Description("Outcome")]
    OUTCOME,

    [Description("Conjunction")]
    CONJUNCTION
}

public static class StepKeywordTypeExtensions
{
    public static string Value(this StepKeywordType v) {
        var attribute = v.GetType().GetField(v.ToString()).GetCustomAttribute<DescriptionAttribute>();
        return attribute == null ? v.ToString() : attribute.Description; 
    }
}
