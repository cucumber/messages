using System;
using System.ComponentModel;
using System.Reflection;

namespace io.cucumber.messages.types;

// Generated code
public enum AttachmentContentEncoding {

    [Description("IDENTITY")]
    IDENTITY,

    [Description("BASE64")]
    BASE64
}

public static class AttachmentContentEncodingExtensions
{
    public static string Value(this AttachmentContentEncoding v) {
        var attribute = v.GetType().GetField(v.ToString()).GetCustomAttribute<DescriptionAttribute>();
        return attribute == null ? v.ToString() : attribute.Description; 
    }
}
