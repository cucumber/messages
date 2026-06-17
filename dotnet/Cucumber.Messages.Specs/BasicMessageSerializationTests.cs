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
using System.Linq;

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
            var env = Envelope.Create(stepDefinition);

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

            var json2 = @"{""id"":""43"",""pickleId"":""24"",""testSteps"":[{""hookId"":""0"",""id"":""39""},{""hookId"":""1"",""id"":""40""},{""id"":""41"",""pickleStepId"":""23"",""stepDefinitionIds"":[],""stepMatchArgumentsLists"":[]},{""hookId"":""4"",""id"":""42""}]}";

            // This test will pass if the deserializer does not throw an exception
            var testCase2 = NdjsonSerializer.Deserialize<TestCase>(json2);
            Assert.Equal(4, testCase2.TestSteps.Count);

            var envText = @"{""testCase"":{""id"":""33"",""pickleId"":""20"",""testSteps"":[{""hookId"":""0"",""id"":""29""},{""hookId"":""1"",""id"":""30""},{""id"":""31"",""pickleStepId"":""19"",""stepDefinitionIds"":[""2""],""stepMatchArgumentsLists"":[{""stepMatchArguments"":[]}]},{""hookId"":""4"",""id"":""32""}]}}
{""testCase"":{""id"":""38"",""pickleId"":""22"",""testSteps"":[{""hookId"":""0"",""id"":""34""},{""hookId"":""1"",""id"":""35""},{""id"":""36"",""pickleStepId"":""21"",""stepDefinitionIds"":[""3""],""stepMatchArgumentsLists"":[{""stepMatchArguments"":[]}]},{""hookId"":""4"",""id"":""37""}]}}
{""testCase"":{""id"":""43"",""pickleId"":""24"",""testSteps"":[{""hookId"":""0"",""id"":""39""},{""hookId"":""1"",""id"":""40""},{""id"":""41"",""pickleStepId"":""23"",""stepDefinitionIds"":[],""stepMatchArgumentsLists"":[]},{""hookId"":""4"",""id"":""42""}]}}
{""testCase"":{""id"":""49"",""pickleId"":""26"",""testSteps"":[{""hookId"":""0"",""id"":""44""},{""hookId"":""1"",""id"":""45""},{""id"":""46"",""pickleStepId"":""25"",""stepDefinitionIds"":[""2""],""stepMatchArgumentsLists"":[{""stepMatchArguments"":[]}]},{""hookId"":""5"",""id"":""47""},{""hookId"":""4"",""id"":""48""}]}}
{""testCase"":{""id"":""55"",""pickleId"":""28"",""testSteps"":[{""hookId"":""0"",""id"":""50""},{""hookId"":""1"",""id"":""51""},{""id"":""52"",""pickleStepId"":""27"",""stepDefinitionIds"":[""2""],""stepMatchArgumentsLists"":[{""stepMatchArguments"":[]}]},{""hookId"":""6"",""id"":""53""},{""hookId"":""4"",""id"":""54""}]}}";
            var lines = envText.Replace("\r\n", "\n").Split("\n").ToList();
            
            List<Envelope> envelopes = new List<Envelope>();

            foreach (var line in lines)
            {
                var envelope = NdjsonSerializer.Deserialize<Envelope>(line);
                envelopes.Add(envelope);
            }
            Assert.Equal(5, envelopes.Count);
        }
    }
}
