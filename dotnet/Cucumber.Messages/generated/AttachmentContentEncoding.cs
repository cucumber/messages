using System.ComponentModel;
using System.Reflection;

namespace Io.Cucumber.Messages.Types;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

public enum AttachmentContentEncoding 
{

    [Description("IDENTITY")]
    IDENTITY,

    [Description("BASE64")]
    BASE64
}

public static class AttachmentContentEncodingExtensions
{
    public static string Value(this AttachmentContentEncoding v)
    {
        var attribute = v.GetType().GetField(v.ToString())?.GetCustomAttribute<DescriptionAttribute>();
        return attribute == null ? v.ToString() : attribute.Description; 
    }
}
