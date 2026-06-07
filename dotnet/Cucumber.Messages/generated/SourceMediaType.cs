using System;
using System.ComponentModel;
using System.Reflection;

namespace Io.Cucumber.Messages.Types;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

public enum SourceMediaType {

    [Description("text/x.cucumber.gherkin+plain")]
    TEXT_X_CUCUMBER_GHERKIN_PLAIN,

    [Description("text/x.cucumber.gherkin+markdown")]
    TEXT_X_CUCUMBER_GHERKIN_MARKDOWN
}

public static class SourceMediaTypeExtensions
{
    public static string Value(this SourceMediaType v) {
        var attribute = v.GetType().GetField(v.ToString()).GetCustomAttribute<DescriptionAttribute>();
        return attribute == null ? v.ToString() : attribute.Description; 
    }
}
