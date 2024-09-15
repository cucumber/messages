using System.ComponentModel;
using System.Reflection;

namespace Io.Cucumber.Messages.Types;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

public enum TestStepResultStatus 
{

    [Description("UNKNOWN")]
    UNKNOWN,

    [Description("PASSED")]
    PASSED,

    [Description("SKIPPED")]
    SKIPPED,

    [Description("PENDING")]
    PENDING,

    [Description("UNDEFINED")]
    UNDEFINED,

    [Description("AMBIGUOUS")]
    AMBIGUOUS,

    [Description("FAILED")]
    FAILED
}

public static class TestStepResultStatusExtensions
{
    public static string Value(this TestStepResultStatus v)
    {
        var attribute = v.GetType().GetField(v.ToString())?.GetCustomAttribute<DescriptionAttribute>();
        return attribute == null ? v.ToString() : attribute.Description; 
    }
}
