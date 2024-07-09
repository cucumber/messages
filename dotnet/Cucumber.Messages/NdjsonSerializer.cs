using Io.Cucumber.Messages.Types;
using System;
using System.Text.Json;

namespace Cucumber.Messages
{
    public class NdjsonSerializer
    {
        private static Lazy<JsonSerializerOptions> _jsonOptions = new Lazy<JsonSerializerOptions>(() =>
        {
            var options = new JsonSerializerOptions();
            options.PropertyNamingPolicy = JsonNamingPolicy.CamelCase;
            options.Converters.Add(new CucumberMessageEnumConverter<AttachmentContentEncoding>());
            options.Converters.Add(new CucumberMessageEnumConverter<PickleStepType>());
            options.Converters.Add(new CucumberMessageEnumConverter<SourceMediaType>());
            options.Converters.Add(new CucumberMessageEnumConverter<StepDefinitionPatternType>());
            options.Converters.Add(new CucumberMessageEnumConverter<StepKeywordType>());
            options.Converters.Add(new CucumberMessageEnumConverter<TestStepResultStatus>());
            options.DefaultIgnoreCondition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull;
            options.Encoder = System.Text.Encodings.Web.JavaScriptEncoder.UnsafeRelaxedJsonEscaping;

            return options;
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

        internal static string Serialize<T>(T message)
        {
            return JsonSerializer.Serialize(message, JsonOptions);
        }

        public static Envelope Deserialize(string json)
        {
            return NdjsonSerializer.Deserialize<Envelope>(json);
        }

        internal static T Deserialize<T>(string json)
        {
            return JsonSerializer.Deserialize<T>(json, JsonOptions);
        }
    }
}
