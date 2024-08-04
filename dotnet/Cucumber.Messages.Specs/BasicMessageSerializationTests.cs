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
            var env = new Envelope(null, null, null, null, null, null, null, null, stepDefinition, null, null, null, null, null, null, null, null, null, null);

            var serializedStepDefinition = NdjsonSerializer.Serialize(env);
            var reconstructedStepDefinition = NdjsonSerializer.Deserialize(serializedStepDefinition);

            var expectedStepDefinition = NdjsonSerializer.Deserialize(stepDefinitionNDJSON);
            Assert.Equal(expectedStepDefinition, reconstructedStepDefinition);
        }

    }
}
