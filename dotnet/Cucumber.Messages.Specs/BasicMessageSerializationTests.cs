using Xunit;
﻿using System.IO;
using Io.Cucumber.Messages.Types;
using System.Text.Json;
using System.Collections.Generic;
using System.Reflection;
using System.Text.Json.Serialization;
using System;
using System.ComponentModel;
using Cucumber.Messages;

namespace Cucumber.Messages.Specs
{
    public class BasicMessageSerializationTests
    {

        [Fact]
        public void SerializesAnEnvelopeToNDJSONCorrectly()
        {
            var stepDefinitionNDJSON = @"{""stepDefinition"":{""id"":""0"",""pattern"":{""source"":""I have {int} cukes in my belly"",""type"":""CUCUMBER_EXPRESSION""},""sourceReference"":{""location"":{""line"":3},""uri"":""samples/minimal/minimal.feature.ts""}}}
";          
            var sourceReference = new SourceReference("samples/minimal/minimal.feature.ts",
                null, null, new Location(3, null));
            var stepDefPattern = new StepDefinitionPattern("I have {int} cukes in my belly", StepDefinitionPatternType.CUCUMBER_EXPRESSION);
            var stepDefinition = new StepDefinition("0", stepDefPattern, sourceReference);
            var env = new Envelope(null, null, null, null, null, null, null, null, stepDefinition, null, null, null, null, null, null, null, null);

            var serializedStepDefinition = NdjsonSerializer.Serialize(env);
            var reconstructedStepDefinition = NdjsonSerializer.Deserialize(serializedStepDefinition);

            var expectedStepDefinition = NdjsonSerializer.Deserialize(stepDefinitionNDJSON);
            Assert.Equal(expectedStepDefinition, reconstructedStepDefinition);
        }

        [Fact]
        public void ProperlyDeserializesCollectionProperties() {

            // The following is from the CCK hooks sample
            var json = @"{""id"":""33"",""pickleId"":""20"",""testSteps"":[{""hookId"":""0"",""id"":""29""},{""hookId"":""1"",""id"":""30""},{""id"":""31"",""pickleStepId"":""19"",""stepDefinitionIds"":[""2""],""stepMatchArgumentsLists"":[{""stepMatchArguments"":[]}]},{""hookId"":""4"",""id"":""32""}]}";

            // This test will pass if the deserializer does not throw an exception
            var testCase = NdjsonSerializer.Deserialize<TestCase>(json);
            Assert.Equal(4, testCase.TestSteps.Count);
        }
    }
}
