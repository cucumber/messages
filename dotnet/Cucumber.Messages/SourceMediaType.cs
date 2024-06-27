using System;
using System.ComponentModel;
using System.Reflection;

namespace io.cucumber.messages.types;

// Generated code
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
