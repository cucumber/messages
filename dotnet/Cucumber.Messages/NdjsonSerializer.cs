using Io.Cucumber.Messages.Types;
using System.Text.Json;

namespace Cucumber.Messages
{
    public static class NdjsonSerializer
    {
        private static object lockObject = new object();
        private static JsonSerializerOptions _jsonOptions;
        private static JsonSerializerOptions JsonOptions { get 
            { 
                if (_jsonOptions == null)
                {
                    lock (lockObject)
                    {
                        if (_jsonOptions == null)
                        {
                            _jsonOptions = new JsonSerializerOptions();
                            _jsonOptions.PropertyNamingPolicy = JsonNamingPolicy.CamelCase;
                            _jsonOptions.Converters.Add(new CucumberMessagEnumConverter<AttachmentContentEncoding>());
                            _jsonOptions.Converters.Add(new CucumberMessagEnumConverter<PickleStepType>());
                            _jsonOptions.Converters.Add(new CucumberMessagEnumConverter<SourceMediaType>());
                            _jsonOptions.Converters.Add(new CucumberMessagEnumConverter<StepDefinitionPatternType>());
                            _jsonOptions.Converters.Add(new CucumberMessagEnumConverter<StepKeywordType>());
                            _jsonOptions.Converters.Add(new CucumberMessagEnumConverter<TestStepResultStatus>());
                            _jsonOptions.DefaultIgnoreCondition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull;
                            _jsonOptions.Encoder = System.Text.Encodings.Web.JavaScriptEncoder.UnsafeRelaxedJsonEscaping;
                        }
                    }
                }
                return _jsonOptions;
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
