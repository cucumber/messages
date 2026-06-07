using System;
using System.ComponentModel;
using System.Reflection;

namespace Io.Cucumber.Messages.Types;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

public enum HookType {

    [Description("BEFORE_TEST_RUN")]
    BEFORE_TEST_RUN,

    [Description("AFTER_TEST_RUN")]
    AFTER_TEST_RUN,

    [Description("BEFORE_TEST_CASE")]
    BEFORE_TEST_CASE,

    [Description("AFTER_TEST_CASE")]
    AFTER_TEST_CASE,

    [Description("BEFORE_TEST_STEP")]
    BEFORE_TEST_STEP,

    [Description("AFTER_TEST_STEP")]
    AFTER_TEST_STEP
}

public static class HookTypeExtensions
{
    public static string Value(this HookType v) {
        var attribute = v.GetType().GetField(v.ToString()).GetCustomAttribute<DescriptionAttribute>();
        return attribute == null ? v.ToString() : attribute.Description; 
    }
}
