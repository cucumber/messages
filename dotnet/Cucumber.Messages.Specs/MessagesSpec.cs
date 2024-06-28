using Xunit;
﻿using System.IO;
using Io.Cucumber.Messages.Types;
using System.Text.Json;
using System.Collections.Generic;
using System.Reflection;
using System.Text.Json.Serialization;
using System;
using System.ComponentModel;

namespace Io.Cucumber.Messages.Specs
{
    public class MessagesSpec
    {
        [Fact]
        public void SerializesAStepDefinitionToNDJSONCorrectly()
        {
            var stepDefinitionNDJSON = @"{""stepDefinition"":{""id"":""0"",""pattern"":{""source"":""I have {int} cukes in my belly"",""type"":""CUCUMBER_EXPRESSION""},""sourceReference"":{""location"":{""line"":3},""uri"":""samples/minimal/minimal.feature.ts""}}}
";          
            var soureReference = new SourceReference("samples/minimal/minimal.feature.ts",
                null, null, new Location(3, null));
            var stepDefPattern = new StepDefinitionPattern("I have {int} cukes in my belly", StepDefinitionPatternType.CUCUMBER_EXPRESSION);
            var stepDefinition = new StepDefinition("0", stepDefPattern, soureReference);
            var env = new Envelope(null, null, null, null, null, null, null, null, stepDefinition, null, null, null, null, null, null, null, null);

            var jsonOptions = new JsonSerializerOptions();
            jsonOptions.PropertyNamingPolicy = JsonNamingPolicy.CamelCase;
            jsonOptions.Converters.Add(new CustomEnumConverter<StepDefinitionPatternType>());
            jsonOptions.DefaultIgnoreCondition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull;

            var serializedStepDefinition = JsonSerializer.Serialize<Envelope>(env, jsonOptions);
            var reconstructedStepDefinition = JsonSerializer.Deserialize<Envelope>(serializedStepDefinition, jsonOptions);

            var expectedStepDefinition = JsonSerializer.Deserialize<Envelope>(stepDefinitionNDJSON, jsonOptions);
            Assert.Equal(expectedStepDefinition, reconstructedStepDefinition);

        }
        public class CustomEnumConverter<T> : JsonConverter<T> where T : struct, Enum
        {
            private readonly Dictionary<T, string> _enumToString = new Dictionary<T, string>();
            private readonly Dictionary<string, T> _stringToEnum = new Dictionary<string, T>();

            public CustomEnumConverter()
            {
                var type = typeof(T);
                foreach (var field in type.GetFields(BindingFlags.Public | BindingFlags.Static))
                {
                    var value = (T)field.GetValue(null);
                    var attribute = field.GetCustomAttribute<DescriptionAttribute>();
                    var name = attribute?.Description ?? field.Name;
                    _enumToString[value] = name;
                    _stringToEnum[name] = value;
                }
            }

            public override T Read(ref Utf8JsonReader reader, Type typeToConvert, JsonSerializerOptions options)
            {
                var stringValue = reader.GetString();
                return _stringToEnum.TryGetValue(stringValue, out var enumValue) ? enumValue : default;
            }

            public override void Write(Utf8JsonWriter writer, T value, JsonSerializerOptions options)
            {
                writer.WriteStringValue(_enumToString.TryGetValue(value, out var stringValue) ? stringValue : value.ToString());
            }
        }
    }
}
