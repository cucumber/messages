﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xunit;

using Cucumber.Messages;
using Io.Cucumber.Messages.Types;

namespace Cucumber.Messages.Specs
{
    public class NdjsonStreamSerializationTests
    {

        [Fact]
        public void WritesSourceEnvelope()
        {
            MemoryStream memoryStream = new MemoryStream();
            var writer = new MessageToNdjsonWriter(memoryStream);
            writer.Write(Envelope.Create(new Source("hello.feature", "Feature: Hello", SourceMediaType.TEXT_X_CUCUMBER_GHERKIN_PLAIN)));

            var json = Encoding.UTF8.GetString(memoryStream.ToArray());
            Assert.Equal(@"{""source"":{""uri"":""hello.feature"",""data"":""Feature: Hello"",""mediaType"":""text/x.cucumber.gherkin+plain""}}"+Environment.NewLine, json);
        }

        [Fact]
        public void DoesNotSerializeNullFields()
        {
            MemoryStream memoryStream = new MemoryStream();
            var writer = new MessageToNdjsonWriter(memoryStream);
            writer.Write(new Envelope(null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null));

            var json = Encoding.UTF8.GetString(memoryStream.ToArray());
            Assert.Equal("{}"+Environment.NewLine, json);
        }

        [Fact]
        public void IgnoresEmptyLines()
        {
            MemoryStream memoryStream = new MemoryStream(Encoding.UTF8.GetBytes("{}\n{}\n\n{}\n"));
            var enumerator = new NdjsonMessageReader(memoryStream).GetEnumerator();
            
            var expectedEnvelope = new Envelope(null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null);
            for (int i = 0; i < 3; i++)
            {
                Assert.True(enumerator.MoveNext());
                Assert.Equal(expectedEnvelope, enumerator.Current);
            }

            Assert.False(enumerator.MoveNext());
        }

        [Fact]
        public void Handles_Enums()
        {
            MemoryStream memoryStream = new MemoryStream(Encoding.UTF8.GetBytes("{\"attachment\":{\"contentEncoding\":\"BASE64\", \"body\":\"the-body\", \"mediaType\":\"text/plain\"}}\n"));
            var enumerator = new NdjsonMessageReader(memoryStream).GetEnumerator();
            Assert.True(enumerator.MoveNext());
            Envelope envelope = enumerator.Current;

            Assert.Equal(AttachmentContentEncoding.BASE64, envelope.Attachment.ContentEncoding);
            Assert.Equal("the-body", envelope.Attachment.Body);
            Assert.Equal("text/plain", envelope.Attachment.MediaType);
            Assert.False(enumerator.MoveNext());
        }

        [Fact]
        public void Handles_Single_Argument_Constructor()
        {
            MemoryStream memoryStream = new MemoryStream(Encoding.UTF8.GetBytes("{\"testRunStarted\": {\"timestamp\":{\"nanos\":0,\"seconds\":0}}}\n"));
            var enumerator = new NdjsonMessageReader(memoryStream).GetEnumerator();
            Assert.True(enumerator.MoveNext());
            Envelope envelope = enumerator.Current;
            Envelope expected = Envelope.Create(new TestRunStarted(new Timestamp(0, 0)));

            Assert.Equal(expected, envelope);
            Assert.False(enumerator.MoveNext());
        }

        [Fact]
        public void Includes_Offending_Line_In_Error_Message()
        {
            MemoryStream memoryStream = new MemoryStream(Encoding.UTF8.GetBytes("BLA BLA"));
            var enumerator = new NdjsonMessageReader(memoryStream).GetEnumerator();
            var exception = Assert.Throws<InvalidOperationException>( () => enumerator.MoveNext());
            Assert.Equal("Could not parse JSON: BLA BLA", exception.Message);
        }
    }
}
