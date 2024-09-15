using System.ComponentModel;
using System.Reflection;

namespace Io.Cucumber.Messages.Types;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

public enum StepKeywordType 
{

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
    public static string Value(this StepKeywordType v)
    {
        var attribute = v.GetType().GetField(v.ToString())?.GetCustomAttribute<DescriptionAttribute>();
        return attribute == null ? v.ToString() : attribute.Description; 
    }
}
