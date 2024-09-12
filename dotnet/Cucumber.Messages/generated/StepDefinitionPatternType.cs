using System;
using System.ComponentModel;
using System.Reflection;

namespace Io.Cucumber.Messages.Types;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

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
