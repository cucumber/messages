using System;
using System.ComponentModel;
using System.Reflection;

namespace io.cucumber.messages.types;

// Generated code
public enum PickleStepType {

    [Description("Unknown")]
    UNKNOWN,

    [Description("Context")]
    CONTEXT,

    [Description("Action")]
    ACTION,

    [Description("Outcome")]
    OUTCOME
}

public static class PickleStepTypeExtensions
{
    public static string Value(this PickleStepType v) {
        var attribute = v.GetType().GetField(v.ToString()).GetCustomAttribute<DescriptionAttribute>();
        return attribute == null ? v.ToString() : attribute.Description; 
    }
}
