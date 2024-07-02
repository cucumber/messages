using Io.Cucumber.Messages.Types;
using System;
using System.Text.Json;

namespace Cucumber.Messages
{
    public static class NdjsonSerializer
    {
        private static object lockObject = new object();
        private static Lazy<JsonSerializerOptions> _jsonOptions = new Lazy<JsonSerializerOptions>(() =>
        {
            var jso = new JsonSerializerOptions();
            jso.PropertyNamingPolicy = JsonNamingPolicy.CamelCase;
            jso.Converters.Add(new CucumberMessagEnumConverter<AttachmentContentEncoding>());
            jso.Converters.Add(new CucumberMessagEnumConverter<PickleStepType>());
            jso.Converters.Add(new CucumberMessagEnumConverter<SourceMediaType>());
            jso.Converters.Add(new CucumberMessagEnumConverter<StepDefinitionPatternType>());
            jso.Converters.Add(new CucumberMessagEnumConverter<StepKeywordType>());
            jso.Converters.Add(new CucumberMessagEnumConverter<TestStepResultStatus>());
            jso.DefaultIgnoreCondition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull;
            jso.Encoder = System.Text.Encodings.Web.JavaScriptEncoder.UnsafeRelaxedJsonEscaping;

            return jso;
        });

        private static JsonSerializerOptions JsonOptions { get 
            { 
                return _jsonOptions.Value;
            }
        } 

        public static string Serialize(Envelope message)
        {
            return NdjsonSerializer.Serialize<Envelope>(message);
        }

        public static string Serialize<T>(T message)
        {
            return JsonSerializer.Serialize(message, JsonOptions);
        }
        public static Envelope Deserialize(string json)
        {
            return NdjsonSerializer.Deserialize<Envelope>(json);
        }

        public static T Deserialize<T>(string json)
        {
            return JsonSerializer.Deserialize<T>(json, JsonOptions);
        }

    }

}
