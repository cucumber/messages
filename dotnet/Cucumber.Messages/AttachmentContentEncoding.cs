using System;

namespace io.cucumber.messages.types;

// Generated code
public enum AttachmentContentEncoding {

    [Description("IDENTITY")]
    IDENTITY,

    [Description("BASE64")]
    BASE64;
    public static string Value(AttachmentContentEncoding v) {
        var attribute = v.GetType().GetField(v.ToString()).GetCustomAttribute<DescriptionAttribute>();
        return attribute == null ? v.ToString() : attribute.Description; 
    }
}
